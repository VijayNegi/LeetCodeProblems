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
    int pseudoPalindromicPaths1 (TreeNode* root) {
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
    int pseudoPalindromicPaths(TreeNode* root, int count = 0) {
        if (!root) return 0;
        count ^= 1 << (root->val - 1);
        int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
        // if both are null check if there is only one bit set
        if (root->left == root->right && (count & (count - 1)) == 0) res++;
        return res;
    }
};
