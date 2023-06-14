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
    // Wrong ans
    int getMinimumDifference1(TreeNode* root) {
        int diff = numeric_limits<int>::max();
        if(!root) return diff;
        if(root->left) diff = min(diff,abs(root->val- root->left->val));
        if(root->right) diff = min(diff,abs(root->val- root->right->val));
        diff = min(diff, getMinimumDifference(root->left));
        diff = min(diff, getMinimumDifference(root->right));
        return diff;
    }
     int minDifference = INT_MAX;
    // Initially, it will be null.
    TreeNode* prevNode;
     void inorderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        
        inorderTraversal(node->left);
        // Find the difference with the previous value if it is there.
        if (prevNode != NULL) {
            minDifference = min(minDifference, node->val - prevNode->val);
        }
        prevNode = node;
        inorderTraversal(node->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        return minDifference;
    }
};
