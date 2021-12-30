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
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool sub = false) {
        
        if(!root && !subRoot)
            return true;
        else if(!root || !subRoot)
            return false;
        if(root->val == subRoot->val)
            if(isSubtree(root->right,subRoot->right,true) && isSubtree(root->left, subRoot->left,true))
                return true;
        if(sub)
            return false;
        if(isSubtree(root->right,subRoot) || isSubtree(root->left,subRoot))
            return true;
        return false;
    }
};
