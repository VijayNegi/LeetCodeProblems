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
    unordered_map<int,int> hash;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        if(hash.count(k-root->val))
            return true;
        hash[root->val] = 1;
        
        if(!findTarget(root->left,k))
            return findTarget(root->right,k);
        return true;
    }
​
};
