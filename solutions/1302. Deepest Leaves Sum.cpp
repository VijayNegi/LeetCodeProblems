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
    int deepestLeavesSum(TreeNode* root) {
        int depth=0;
        int sum=0;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* node,int d){
            if(!node)
                return;
            if(d==depth)
                sum += node->val;
            else if(d>depth) {
                depth = d;
                sum = node->val;
            }
                
            dfs(node->left,d+1);
            dfs(node->right,d+1);
        };
        dfs(root,0);
        return sum;
    }
};
