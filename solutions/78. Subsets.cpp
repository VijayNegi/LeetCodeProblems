class Solution {
public:
    // 3 ms
    vector<vector<int>> subsets1(vector<int>& nums) {
        vector<vector<int>> s;
        s.push_back({});
        
        for(auto n:nums)
        {
            vector<vector<int>> t = s;
            for(auto& v:t)
                v.push_back(n);
            s.insert(s.end(),t.begin(),t.end());
        }
        return s;
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<vector<int>> ans;
        int n = v.size(), sz = pow(2,n);        
        for(int i=0; i<sz; i++) {
            vector<int> tmp;
            for(int j=0; j<n; j++) if(i & (1<<j)) tmp.push_back(v[j]);
            ans.push_back(tmp);
        }        
        return ans;
    }
};
