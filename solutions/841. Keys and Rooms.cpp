class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        int count=0;
        while(q.size()){
            int r = q.front();
            q.pop();
            if(visited[r])
                continue;
            visited[r] = true;
            ++count;
            for(auto k:rooms[r])
                q.push(k);
        }
        return n==count;
    }
};
