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
    
    int dfs(TreeNode* root,int maxVal)
    {
        if(!root)
            return 0;
        int ans=0;
        if(root->val>=maxVal)
            ++ans;
        maxVal = max(root->val,maxVal);
        
        ans += dfs(root->right,maxVal);
        ans += dfs(root->left,maxVal);
        return ans;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};
