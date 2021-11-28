class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int dst = graph.size() -1;
        vector<vector<int>> res;
        vector<int> path = {0};
        function<void(void)> dfs = [&]()
        {
            int s = path.size();
            int o = path[s-1];
            
            if(o==dst)
            {
                res.push_back(path);
                return;
            }
            for(auto& n:graph[o])
            {
                path.push_back(n);
                dfs();
                path.pop_back();
            }
        };
        
        
        dfs();
        
        return res;
    }
};
