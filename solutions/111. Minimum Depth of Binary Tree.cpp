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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        vector<TreeNode*> queue;
        queue.push_back(root);
        int depth=1;
        while(queue.size()){
            vector<TreeNode*> next;
            for(auto& node: queue){
                if(!node->left && !node->right)
                    return depth;
                if(node->left) next.push_back(node->left);
                if(node->right) next.push_back(node->right);
            }
            swap(next,queue);
            ++depth;
        }
        return depth;
    }
};
