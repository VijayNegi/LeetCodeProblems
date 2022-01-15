class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return n-1;
        
        unordered_map<int,vector<int>> value_indexes;
        
        for(int i=0;i<n;++i)
            value_indexes[arr[i]].push_back(i);
        
        vector<bool> visited(n,false);
        int dist = 0;
        list<int> que;
        que.push_back(0);
        visited[0] = true;
        list<int> child;
        //bfs
        while(!que.empty())
        {
            int idx = que.front();
            que.pop_front();
            //visited[idx] = true;
            
            if(idx == n-1)
                return dist;
            
            if(idx-1>=0 && !visited[idx-1])
            {
                child.push_back(idx-1);
                visited[idx-1] = true;
            }
                
            if(idx+1<n && !visited[idx+1])
            {
                child.push_back(idx+1);
                visited[idx+1] = true;
            }
                
            
            for(auto& i:value_indexes[arr[idx]])
            {
                if(visited[i])
                    continue;
                child.push_back(i);
                visited[i] = true;
            }
            
            value_indexes[arr[idx]].clear();
                        
            if(que.empty())
            {
                ++dist;
                swap(que,child);
            }
            
        }
        
        return dist;
    }
};
