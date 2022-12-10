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
const int mod = 1e9+7;
class Solution {
public:
    int maxProduct(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int total = 0;
        while(q.size()){
            TreeNode* node = q.front();
            total += node->val;
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        long product = 0;
        dfs(root,product,total);
        return product%mod;
        
    }
    int dfs(TreeNode* node, long& product, int total){
        if(!node) return 0;
        
        long left = dfs(node->left,product,total);
        long right = dfs(node->right,product,total);
        product = max(product,(left*(total-left)));
        product = max(product,(right*(total-right)));
        return left+right+ node->val;
    }
};
