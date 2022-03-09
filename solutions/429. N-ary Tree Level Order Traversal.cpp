/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
​
    Node() {}
​
    Node(int _val) {
        val = _val;
    }
​
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
​
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> result;
        if(!root)
            return result;
        vector<Node*> level;
        level.push_back(root);
        while(!level.empty())
        {
            vector<Node*> next;
            vector<int> vals;
            for(auto node:level)
            {
                vals.push_back(node->val);
                next.insert(next.end(),node->children.begin(),node->children.end());
            }
            swap(level,next);
            result.push_back(vals);
        }
        return result;
    }
};
