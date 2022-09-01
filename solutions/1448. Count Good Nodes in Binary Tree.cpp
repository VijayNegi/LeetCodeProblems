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
    int goodNodes1(TreeNode* root) {
        int count=0;
        function<void(TreeNode*,int)> dfs = [&](TreeNode* node,int maxVal){
            if(!node)
                return;
            if(node->val>=maxVal)
                ++count;
            maxVal = max(maxVal,node->val);
            dfs(node->left,maxVal);
            dfs(node->right,maxVal);
        };
        dfs(root,INT_MIN);
        return count;
    }
    int goodNodes(TreeNode* root,int maxVal= INT_MIN) {
        int count=0;
        if(!root)
            return count;
        if(root->val>=maxVal)
            ++count;
        maxVal = max(maxVal,root->val);
        count += goodNodes(root->left,maxVal);
        count += goodNodes(root->right,maxVal);
        return count;
    }
};
