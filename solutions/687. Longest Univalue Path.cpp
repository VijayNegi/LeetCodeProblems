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
    int longestUnivaluePath(TreeNode* root) {
        if(!root)
            return 0;
        int res=1;
        function<int(TreeNode*)> findPath = [&](TreeNode* root)
        {
            int left=0,right=0;
            if(root->left)
            {
                if(root->left->val == root->val)
                    left = findPath(root->left);
                else
                    findPath(root->left);
            }
            if(root->right)
            {
                if(root->right->val == root->val)
                    right = findPath(root->right);
                else
                    findPath(root->right);
            }
            res = max(res,left+right +1);
            return max(left +1 ,right+1);
        };
        findPath(root);
        return res-1;
    }
};
