class Solution {
public:
    //stl: 3 ms
    vector<vector<int>> permuteUnique1(vector<int>& nums) {
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        do {
            result.push_back(nums);
        } while(std::next_permutation(nums.begin(), nums.end()));
        return result;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        //set<vector<int>> st;
        vector<vector<int>> result;
        vector<int> mp(21,0);
        for(auto n:nums)
            mp[n+10]++;
        
        vector<int> res;
        function<void(int)> dfs = [&](int n){
            if(n==0)
            {
                //st.insert(res);
                result.push_back(res);
                return;
            }
            
            for(int i=0;i<=20;++i)
            {
                if(mp[i]!=0)
                {
                    res.push_back(i-10);
                    mp[i]--;
                    dfs(n-1);
                    mp[i]++;
                    res.pop_back();
                }
            }
        };
        dfs(nums.size());
        //return vector(st.begin(),st.end());
        return result;
    }
};
