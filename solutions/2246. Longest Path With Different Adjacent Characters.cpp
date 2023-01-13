class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> child(n+1);
        for(int i=1;i<n;++i){
            child[parent[i]].push_back(i);
        }
        int result = 1;
        function<int(int)> dfs = [&](int node){
            vector<int> len;
            for(auto& c:child[node]){
                int k = dfs(c);
                if(s[node] != s[c])
                    len.push_back(k);
            }
            if(len.size()==0)
                return 1;
            sort(len.begin(),len.end(),greater<>());
            int res = len[0] +1;
            if(len.size()>=2)
                res += len[1];
            result = max(result,res);
            return len[0] +1;
        };
        dfs(0);
        return result;
    }
};
