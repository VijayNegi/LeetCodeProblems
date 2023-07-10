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
    int min_depth{INT_MAX};
public:
    int minDepth1(TreeNode* root,int depth = 1) {
        if(!root) return 0;
        if(!root->left && !root->right)
            min_depth = min(min_depth, depth);
        minDepth1(root->left,depth+1);
        minDepth1(root->right, depth+1);
        return min_depth;
    }
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
