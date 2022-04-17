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
    TreeNode* convertBST(TreeNode* root) {
        function<void(TreeNode*,int&)> dfs = [&](TreeNode* node,int& sum)
        {
            if(!node)
                return;
            dfs(node->right,sum);
            sum += node->val;
            node->val = sum;
            dfs(node->left,sum);
        };
        int sum = 0;
        dfs(root,sum);
        return root;
    }
};
