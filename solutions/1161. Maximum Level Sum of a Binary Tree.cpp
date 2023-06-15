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
    int maxLevelSum(TreeNode* root) {
        vector<TreeNode*> nodes;
        nodes.push_back(root);
        int level = 1;
        int result = 1;
        int sum = numeric_limits<int>::min();
        while(nodes.size()){
            vector<TreeNode*> next;
            int tsum=0;
            for(auto n:nodes){
                tsum += n->val;
                if(n->left) next.push_back(n->left);
                if(n->right) next.push_back(n->right);
            }
            if(tsum>sum){
                sum=tsum;
                result = level;
            }
            swap(nodes,next);
            ++level;
        }
        return result;
    }
};
