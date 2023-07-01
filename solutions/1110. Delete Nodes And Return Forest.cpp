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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        if(to_delete.size()==0) return {root};
        unordered_set<int> del(begin(to_delete),end(to_delete));
        function<bool(TreeNode*,int)> traverse = [&](TreeNode* node,int parent) -> bool {
            if(!node) return false;
            if(del.count(parent) && !del.count(node->val))
                result.push_back(node);
            if(traverse(node->left,node->val))
               node->left = nullptr;
            if(traverse(node->right,node->val))
               node->right = nullptr;
            return del.count(node->val);
        };
        
        traverse(root,to_delete[0]);
        return result;
    }
};
