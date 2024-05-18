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
    int distributeCoins(TreeNode* root) {
        auto res = dfs(root);
        return res.second;
    }
    // coin balance, internal distance   
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        
        int c = left.first + right.first+root->val-1;
        int d = abs(left.first) + abs(right.first) +left.second + right.second;
​
        return {c,d};
        
    }
};
