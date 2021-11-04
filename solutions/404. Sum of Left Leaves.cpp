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
    int sumOfLeftLeaves(TreeNode* root) {
        int leftSum = 0;
        const function<void(TreeNode* node,bool)> dfs = [&](TreeNode* node, bool left)
        {
            if(!node)
                return;
            if(left && !(node->left) && !(node->right))
            {
                leftSum += node->val;
                return;
            }
            dfs(node->left,true);
            dfs(node->right,false);
        };
        
        dfs(root,false);
        return leftSum;
    }
};
