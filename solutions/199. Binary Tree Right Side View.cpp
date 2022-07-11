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
    vector<int> rightSideView(TreeNode* root) {
        unordered_map<int,int> depthvalue;
        int depth=0;
        vector<pair<TreeNode*,int>> stk;
        TreeNode* node = root;
        while(node) {
            stk.push_back({node,depth});
            node = node->left;
            ++depth;
        }
      
        while(stk.size()) {
            auto curr = stk.back();
            stk.pop_back();
            node = curr.first->right;
            int rdepth = curr.second+1;
            while(node) {
                stk.push_back({node,rdepth});
                node = node->left;
                ++rdepth;
            }
            depthvalue[curr.second] = curr.first->val;
        }
        depth = 0;
        vector<int> result;
        while(depthvalue.count(depth)) {
            result.push_back(depthvalue[depth++]);
        }
        return result;
    }
};
