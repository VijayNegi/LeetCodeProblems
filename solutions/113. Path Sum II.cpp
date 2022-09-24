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
    vector<vector<int>> result;
    void dfs(TreeNode* root, vector<int>& path,int sum,int targetsum)
    {
        if(root==nullptr)
            return;
        sum += root->val;
        path.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr)
        {
            if(sum == targetsum)
            {
                result.push_back(path);
            }
        }
        else
        {
            dfs(root->left,path,sum,targetsum);
            dfs(root->right,path,sum,targetsum);    
        }
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        result.clear();
        vector<int> path;
        dfs(root,path,0,targetSum);
        return result;
    }
};
