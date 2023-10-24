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
    vector<int> largestValues(TreeNode* root) {
        vector<TreeNode*> level,child;
        vector<int> result;
        if(!root) return result;
        level.push_back(root);
        while(level.size())
        {
            int lmax=numeric_limits<int>::min();
            child.clear();
            for(auto& node:level){
                lmax = max(lmax,node->val);
                if(node->left) child.push_back(node->left);
                if(node->right) child.push_back(node->right);
            }
            result.push_back(lmax);
            swap(level,child);
        }
        return result;
    }
};
