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
    bool isCompleteTree(TreeNode* root) {
        vector<TreeNode*> level;
        level.push_back(root);
        bool pre_miss = false;
        while(level.size()){
            vector<TreeNode*> next;
            bool miss = false;
            for(auto& node:level){
                if(miss && (node->left || node->right))
                   return false;
                if(!node->left && node->right)
                    return false;
                if(!node->left || !node->right)
                    miss = true;
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            if(pre_miss && next.size()) return false;
            pre_miss = miss;
            swap(level,next);
        }
        return true;
    }
};
