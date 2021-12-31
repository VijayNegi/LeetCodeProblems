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
    int maxAncestorDiff(TreeNode* root) {
        
        int maxDiff = 0;
        function<void(TreeNode*,int,int)> findAbsDiff = [&](TreeNode* node,int low,int high)
        {
            if(!node)
                return;
            low = min(node->val,low);
            high = max(node->val,high);
            
            maxDiff = max(high - low,maxDiff);
            
            findAbsDiff(node->left,low,high);
            findAbsDiff(node->right,low,high);
        };
        
        findAbsDiff(root,root->val,root->val);
        return maxDiff;
        
    }
};
