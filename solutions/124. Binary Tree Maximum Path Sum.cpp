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
    int maxPathSum(TreeNode* root) {
        int maxPath=INT_MIN;
        dfs(root,maxPath);
        return maxPath;
    }
    int dfs(TreeNode* node, int& maxPath){
        if(!node) return 0;
        int path= node->val;
        int left = max(0,dfs(node->left,maxPath));
        int right = max(0,dfs(node->right,maxPath));
        path += left+right;
        if(maxPath < path)
            maxPath = path;
        return node->val + max(left,right);
    }
};
