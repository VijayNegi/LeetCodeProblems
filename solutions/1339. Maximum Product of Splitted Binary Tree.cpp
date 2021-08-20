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
    int maxProduct(TreeNode* root) {
        long long product=0;
        int  e = 10e8 + 7;
        long long tsum = getSum(root);
        getProduct(root,product,tsum);
     
        return product%e;
    }
    long long getSum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        return root->val + getSum(root->left) + getSum(root->right);
    }
    long long getProduct(TreeNode* root,long long& product,long long& tsum)
    {
        if(!root)
            return 0;
        // long long sLeft = getProduct(root->left, product, tsum);
        // long long sRight = getProduct(root->right,product, tsum);
        long long sum = root->val+  getProduct(root->left, product, tsum)+  getProduct(root->right,product, tsum);
        product  = max((tsum - sum) * sum, product );
        
        return sum;
    }
};
