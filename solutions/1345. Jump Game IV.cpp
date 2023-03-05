class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        map<int,vector<int>> val2id;
        for(int i=0;i<n;++i){
            val2id[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        int depth=0;
        vector<bool> visited(n,false);
        visited[0] = true;
        while(q.size()){
            int k = q.size();
            while(k--){
                int next = q.front();
                q.pop();
                if(next == n-1)
                    return depth;
                if(next>0 && !visited[next-1]){
                    q.push(next-1);
                    visited[next-1] = true;
                }
                    
                if(next<n-1 && !visited[next+1]){
                    q.push(next+1);
                    visited[next+1] = true;
                }
                for(auto& i:val2id[arr[next]]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = true;
                    }
                }
                val2id[arr[next]].clear(); // imp optimization
            }
            ++depth;
        }
        return -1;
    }
};
