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
    int sumRootToLeaf(TreeNode* root) {
        
        int sum=0;
        function<void(TreeNode*, int)> findSum = [&](TreeNode* node, int currSum)
        {
            if(!node) return;
            
            currSum = (currSum << 1) + node->val;
            if(!node->left && !node->right)
                sum += currSum;
            if(node->left)
                findSum(node->left,currSum);
            if(node->right)
                findSum(node->right,currSum);
            
            return;
        };
        
        findSum(root,0);
        return sum;
    }
};
