class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        int n = graph.size();
        vector<int> path;
        function<void(int)> dfs = [&](int node){
            path.push_back(node);
            if(node == n-1){
                result.push_back(path);
                path.pop_back();
                return;
            }
            for(auto k:graph[node])
                dfs(k);
            path.pop_back();
        };
        dfs(0);
        return result;
    }
};
