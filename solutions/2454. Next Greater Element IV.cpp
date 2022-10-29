class Solution {
public:
    //self: 295ms
    vector<int> secondGreaterElement1(vector<int>& nums) {
        int n =nums.size();
        vector<int> nextGreater(n,n);
        vector<int> stk;
        for(int i=n-1;i>=0;--i){
            while(stk.size() && nums[stk.back()]<= nums[i])
                stk.pop_back();
            if(stk.size())
                nextGreater[i] = stk.back();
            stk.push_back(i);
        }
        vector<int> result;
        for(int i=0;i<n;++i){
            if(nextGreater[i]==n){
                result.push_back(-1);
            }
            else{
                int pos = nextGreater[i]+1;
                while(pos<n && nums[pos]<=nums[i] )
                    pos = nextGreater[pos];
                if(pos<n)
                    result.push_back(nums[pos]);
                else
                    result.push_back(-1); 
            }
        }
        return result;
    }
    // just more cleaner
    // 352 ms
    vector<int> secondGreaterElement2(vector<int>& nums) {
        int n = nums.size();
        int nextBig[n+4];
        nextBig[n]=nextBig[n-1]=n;
        for(int i=n-1; i>=0; i--){
            int pos=i+1;
            while(pos<n && nums[pos]<= nums[i] )
                pos = nextBig[pos];
            nextBig[i]=pos;
        }
        vector<int>ans(n);
        int pos;
        for(int i=0; i<n; i++){
            pos = nextBig[i];
            pos++;
            while(pos<n && nums[pos]<=nums[i]){
                pos = nextBig[pos];
            }
            if(pos<n) ans[i]=nums[pos];
            else ans[i]=-1;
        }
        return ans;
    }
    //https://leetcode.com/problems/next-greater-element-iv/discuss/2756668/JavaC%2B%2BPython-One-Pass-Stack-Solution-O(n)
    // 265ms
    vector<int> secondGreaterElement(vector<int>& A) {
        int n = A.size();
        vector<int> res(n, -1), s1, s2, tmp;
        for (int i = 0 ;i < n; ++i) {
            while (!s2.empty() && A[s2.back()] < A[i])
                res[s2.back()] = A[i], s2.pop_back();
            while (!s1.empty() && A[s1.back()] < A[i])
                tmp.push_back(s1.back()), s1.pop_back();
            while (!tmp.empty())
                s2.push_back(tmp.back()), tmp.pop_back();
            s1.push_back(i);
        }
        return res;
    }
};
