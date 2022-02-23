/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
​
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> copy;
        function<Node*(Node*)> dfs = [&](Node* root) -> Node*
        {
            if(!root)
                return nullptr;
            if(copy.find(root) != copy.end())
                return copy[root];
            copy[root] = new Node(root->val);
            Node* curr = copy[root];
            for(auto n:root->neighbors)
                curr->neighbors.push_back(dfs(n));
            return curr;
        };
        
        return dfs(node);
    }
};
