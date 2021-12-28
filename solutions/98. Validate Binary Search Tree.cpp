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
    bool isValidBST(TreeNode* root) {
        
        function<bool(TreeNode*,long,long)> isValid = [&](TreeNode* node,long low,long high)
        {
            if(!node)
                return true;
            if(!(node->val > low && node->val < high))
                return false;
            
            return isValid(node->left,low,node->val) && isValid(node->right,node->val,high);
        
        };
        
        return isValid(root,LONG_MIN,LONG_MAX);
    }
};
