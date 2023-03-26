class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visit(n,false);
        vector<bool> pre(n,false);
        int result=-1;
        int d = 0;
        function<void(int)> dfs = [&](int node){
            if(node < 0 || pre[node]) return;
            if(visit[node]){
                int temp=1,curr=node;
                //inLoop[node] = 1;
                while(edges[curr] != node){
                    curr = edges[curr];
                    visit[curr] = true;
                    ++temp;
                }
                result = max(temp,result);
                
            }
            else {
                visit[node] = true;
                dfs(edges[node]);
            }
        };
        
        for(int i=0;i<n;++i){
            if(!visit[i]){
                dfs(i);
                pre = visit;
            }
        }
        return result;
    }
};
