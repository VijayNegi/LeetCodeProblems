class Solution {
public:
    // backtrack, seems like they have updated the testcases and this solution is not working now, which was accepted in the past
    // [13,11,1,8,6,7,8,8,6,7,8,9,8]
    bool makesquare1(vector<int>& mtcks) {
        int n = mtcks.size();
        int tlen = accumulate(begin(mtcks),end(mtcks),0);
        if(tlen%4)
            return false;
        int rectSide = tlen/4;
        vector<bool> used(n,false);
        sort(begin(mtcks),end(mtcks),greater<>());
        function<bool(int,int)> dfs = [&](int slen,int idx) {
            if(idx>=n)
                return false;
                
            if((slen < mtcks[idx]) || used[idx])
                return dfs(slen,idx+1);
            else if(slen>mtcks[idx] ) {
                used[idx] = true;
                slen -= mtcks[idx];
                if(dfs(slen,idx+1))
                    return true;
                used[idx] = false;
                slen += mtcks[idx];
                return dfs(slen,idx+1);
            }
            else {
                used[idx] = true;
                return true;
            }
            return false;
        };
        cout<<rectSide<<endl;
        for(int i=0;i<3;++i) {
            cout<<"1"<<endl;
            if(!dfs(rectSide,0))
                return false;
        }
            
        return true;
    }
    // TLE : find all ways to make match side and try to find 4 mutually exclusive side patterns
    bool makesquare2(vector<int>& mtcks) {
        int n = mtcks.size();
        int tlen = accumulate(begin(mtcks),end(mtcks),0);
        if(tlen%4)
            return false;
        int rectSide = tlen/4;
        sort(begin(mtcks),end(mtcks),greater<>());
        unordered_set<int> group;
        function<void(int,int,int bmap)> dfs = [&](int slen,int idx,int bmap) {
            if(idx>=n)
                return;
            dfs(slen,idx+1,bmap);
            if(slen == mtcks[idx]) {
                bmap |= 1<<idx;
                //cout<<" b "<<bmap<<endl;
                group.insert(bmap);
            }
            else if(slen>mtcks[idx]) {
                slen -= mtcks[idx];
                bmap |= 1<<idx;
                dfs(slen,idx+1, bmap);
            }
            return;
        };
        dfs(rectSide,0,0);
        if(group.size()<4)
            return false;
        if(group.size()==4)
            return true;
        cout<<group.size()<<endl;
        vector<int> result;
        for(auto n:group) {
            vector<int> temp=result;
            for(auto k:result) {
                if((n & k) == 0 )
                    temp.push_back(n|k);
            }
            temp.push_back(n);
            result = temp;
        }
        int val = (1<<n)-1;
        for(auto k:result) 
            if(k == val)
                return true;
        return false;
    }
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) 
                continue;
            int j = i;
            while (--j >= 0) 
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }
    //https://leetcode.com/problems/matchsticks-to-square/discuss/95744/cpp-6ms-solution-with-DFS
    // backtrack : 21 ms
    bool makesquare3(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(begin(nums),end(nums),0);
        if (sum % 4 != 0) return false;
        sort(begin(nums),end(nums),greater<>()); 
        if(nums[0] > sum/4)
            return false;
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, sum / 4);
    }
    // another neat solution : 391 ms
    //https://leetcode.com/problems/partition-to-k-equal-sum-subsets/discuss/480707/C%2B%2B-DP-bit-manipulation-in-20-lines
     bool makesquare(vector<int>& nums) {
        int k=4;
        int n = nums.size(), sum = 0;
        vector<int> dp((1<<16)+2,-1);
        //fill(dp, dp+(1<<16)+2, -1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum % k) return false;
        int tar = sum/k;
        
        for (int mask = 0; mask < (1<<n); mask++) {
            if (dp[mask] == -1) continue;  // if current state is illegal, simply ignore it
            for (int i = 0; i < n; i++) {
                if (!(mask&(1<<i)) && dp[mask]+nums[i] <= tar) {  // if nums[i] is unchosen && choose nums[i] would not cross the target
                    dp[mask|(1<<i)] = (dp[mask]+nums[i]) % tar;
                }
            }
        }
        return dp[(1<<n)-1] == 0;
    }
    
};
