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
    int rob(TreeNode* root) {
        
        unordered_map<TreeNode*,pair<int,int>> dp;
        function<int(TreeNode*,bool)> dfs = [&](TreeNode* r, bool select){
            if(!r)
                  return 0;
            else if(!r->left && !r->right)
            {
                
                if(select)
                    return r->val;
                return 0;
            }
            
            if(!dp.count(r))
            {
                int selectChild = dfs(r->left,true)+dfs(r->right,true);
                int selectRoot = dfs(r->left,false)+dfs(r->right,false)+r->val;
                dp[r] = {selectChild,selectRoot};
            }
            
            if(select)
                return max(dp[r].first,dp[r].second);
            
            return dp[r].first;
        };
        
        return dfs(root,true);
​
    }
};
