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
    int result{INT_MAX};
public:
    int minDiffInBST1(TreeNode* root) {
        minDiff(root);
        return result;
    }
    pair<int,int> minDiff(TreeNode* root){
        if(!root) return {1e6,-1};
        auto left = minDiff(root->left);
        auto right = minDiff(root->right);
        if(root->left)
            result = min(result,root->val - left.second);
        if(root->right)
            result = min(result,right.first - root->val);
        return {min(left.first,root->val), max(right.second,root->val)};
    }
    void helper(TreeNode* root, int& minDiff, int& prevVal) {
        if (root == nullptr)
            return;
        helper(root -> left, minDiff, prevVal);
        if (prevVal != -1) {
            minDiff = min(minDiff, root -> val - prevVal);
        }
        prevVal = root -> val;
        helper(root -> right, minDiff, prevVal);
        
    }
    int minDiffInBST(TreeNode* root) {
        int minDiff = INT_MAX;
        int prevVal = -1;
        helper(root, minDiff, prevVal);
        return minDiff;
    }
};
