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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        vector<TreeNode*> stk;
        function<void(TreeNode*)> pushLeft = [&](TreeNode* node){
            while(node){
                stk.push_back(node);
                node = node->left;
            }
        };
        
        pushLeft(root);
        while(stk.size()){
            TreeNode* node = stk.back();
            stk.pop_back();
            result.push_back(node->val);
            pushLeft(node->right);
        }
        return result;
    }
};
