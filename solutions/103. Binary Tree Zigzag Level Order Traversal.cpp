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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        while(q.size()){
            int count = q.size();
            vector<int> level;
            while(count--){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(flag)
                reverse(begin(level),end(level));
            flag = !flag;
            result.push_back(level);
        }
        return result;
    }
};
