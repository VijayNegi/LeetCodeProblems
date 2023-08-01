class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> curr;
        function<void(int)> dfs = [&](int i){
            if(curr.size() == k){
                result.push_back(curr);
                return;
            }
            if(i > n) return;
            curr.push_back(i);
            dfs(i+1);
            curr.pop_back();
            dfs(i+1);
        };
        dfs(1);
        return result;
    }
};
