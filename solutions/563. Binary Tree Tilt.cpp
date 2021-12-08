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
    int findTilt(TreeNode* root) {
        
        if(!root)
            return 0;
        
        function<int(TreeNode*,int&)> tiltSum = [&](TreeNode* node, int& sum){
            if(!node)
                return 0;
            int leftSum = tiltSum(node->left,sum);
            int rightSum = tiltSum(node->right,sum);
            
            sum += abs(leftSum-rightSum);
            return leftSum + rightSum + node->val;
        };
        
        int tiltTotal = 0;
        tiltSum(root,tiltTotal);
        return tiltTotal;
        
    }
};
