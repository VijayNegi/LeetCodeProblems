/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_set<int> hash;
public:
    bool findTarget1(TreeNode* root, int k) {
        unordered_map<int,int> seen;
        stack<TreeNode*> stk;
        function<void(TreeNode*)> push_left = [&](TreeNode* node) {
            while(node) {
                stk.push(node);
                node = node->left;
            }
        };
        push_left(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            push_left(node->right);
            if(seen.count(k-node->val))
                return true;
            seen[node->val] = 1;
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(!root)                       return false;
        if(hash.count(k- root->val))    return true;
        hash.insert(root->val);
        if(!findTarget(root->left,k))
            return findTarget(root->right,k);
        return true;
    }
};
