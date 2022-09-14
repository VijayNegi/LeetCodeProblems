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
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10,0);
        int result=0;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if(!node) return;
            count[node->val]++;
            if(!node->left && !node->right) {
                int odd=0;
                for(auto&v : count)
                    if(v & 1) ++odd;
                if(odd<=1) ++result;
            }
            if(node->right)
                dfs(node->right);
            if(node->left)
                dfs(node->left);
            count[node->val]--;
            return;
            
        };
        dfs(root);
        return result;
    }
};
