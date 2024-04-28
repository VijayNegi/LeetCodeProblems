class Solution {
    vector<unordered_set<int>> tree;
    vector<int> res, count;
public:
 // https://leetcode.com/problems/sum-of-distances-in-tree/discuss/130583/C%2B%2BJavaPython-Pre-order-and-Post-order-DFS-O(N)
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        tree.resize(N);
        res.assign(N, 0);
        count.assign(N, 1);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        dfs(0, -1); // pre Traversal : To collect initial data, childs and solve for first node.
        dfs2(0, -1); // Post Traversal : Use previously collected data and solve for other nodes.
        return res;
​
    }
​
    void dfs(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            dfs(i, root);
            count[root] += count[i];   // add childs of i including i.
            res[root] += res[i] + count[i]; // add distance for all nodes, note: we need to add count as we need to travel same path for all child nodes
        }
    }
​
    void dfs2(int root, int pre) {
        for (auto i : tree[root]) {
            if (i == pre) continue;
            res[i] = res[root] - count[i] + count.size() - count[i]; // res[root] - count[i] : nodes moving closer too
                                                                     // N - count[i] : nodes moving 
            dfs2(i, root);
        }
    }
​
};
