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
    int diameterOfBinaryTree(TreeNode* root) {
        int result = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* root)
        {
            if(!root)
                return 0;
            int left = dfs(root->left) + (root->left?1:0);
            int right = dfs(root->right) + (root->right?1:0);
            result = max(result,left+right);
            return max(left,right);
        };
        dfs(root);
        return result;
    }
};
