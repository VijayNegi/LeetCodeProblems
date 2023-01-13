class Solution {
public:
    int longestPath1(vector<int>& parent, string s) {
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
    // more clean
    int longestPath(vector<int>& parent, string s) {
        int n = s.size(), res = 0;
        vector<vector<int>> children(n, vector<int>());
        for (int i = 1; i < n; ++i)
            children[parent[i]].push_back(i);
        dfs(children, s, res, 0);
        return res;
    }
​
    int dfs(vector<vector<int>>& children, string& s, int& res, int i) {
        int big1 = 0, big2 = 0;
        for (int& j : children[i]) {
            int cur = dfs(children, s, res, j);
            if (s[i] == s[j]) continue;
            if (cur > big2) big2 = cur;
            if (big2 > big1) swap(big1, big2);
        }
        res = max(res, big1 + big2 + 1);
        return big1 + 1;
    }
};
