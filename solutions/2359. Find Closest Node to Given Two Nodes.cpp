class Solution {
public:
    // self : 233ms
    int closestMeetingNode1(vector<int>& edges, int node1, int node2) {
        int result=node1<node2? node1:node2;
        if(node1==node2)
            return result;
        int n1 = node1,n2 = node2;
        unordered_set<int> s1{node1},s2{node2};
        while(edges[n1] >= 0 || edges[n2]>=0){
            if(edges[n1]>=0){
                s1.insert(edges[n1]);
                int t = n1;
                n1 = edges[n1];
                edges[t] = -1;
            }
            if(edges[n2]>=0){
                s2.insert(edges[n2]);
                int t = n2;
                n2 = edges[n2];
                edges[t] = -1;
            }
            if(s1.count(n2) && s2.count(n1)){
                return n1<n2? n1:n2;
            }
            else if(s1.count(n2) )
                return n2;
            else if(s2.count(n1))
                return n1;
        }
        return -1;
    }
    // official: 191ms 
    void bfs(int startNode, vector<int>& edges, vector<int>& dist) {
        int n = edges.size();
        queue<int> q;
        q.push(startNode);

        vector<bool> visit(n);
        dist[startNode] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (visit[node]) {
                continue;
            }

            visit[node] = true;
            int neighbor = edges[node];
            if (neighbor != -1 && !visit[neighbor]) {
                dist[neighbor] = 1 + dist[node];
                q.push(neighbor);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, numeric_limits<int>::max()), dist2(n, numeric_limits<int>::max());

        bfs(node1, edges, dist1);
        bfs(node2, edges, dist2);

        int minDistNode = -1, minDistTillNow = numeric_limits<int>::max();
        for (int currNode = 0; currNode < n; currNode++) {
            if (minDistTillNow > max(dist1[currNode], dist2[currNode])) {
                minDistNode = currNode;
                minDistTillNow = max(dist1[currNode], dist2[currNode]);
            }
        }

        return minDistNode;
    }
};
