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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,TreeNode*> seen;
        set<TreeNode*> res;
        function<string(TreeNode*)> dfs = [&](TreeNode* node)->string{
            if(!node) return "x";
            string r = dfs(node->left);
            r += ","+dfs(node->right);
            r = to_string(node->val)+","+r;
            if(seen.count(r))
                res.insert(seen[r]);
            else
                seen[r] = node;
            return r;
        };
        dfs(root);
        vector<TreeNode*> result{res.begin(),res.end()};
        return result;
        
    }
};
