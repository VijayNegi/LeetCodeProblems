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
    int longestZigZag(TreeNode* root) {
        int res=0;
        function<void(TreeNode*,int,int)> dfs = [&](TreeNode* node,int left,int right){
            if(!node) return;
            res = max(res,max(left,right));
            dfs(node->left,0,left+1);
            dfs(node->right,right+1,0);
        };
        dfs(root,0,0);
        return res;
    }
};
