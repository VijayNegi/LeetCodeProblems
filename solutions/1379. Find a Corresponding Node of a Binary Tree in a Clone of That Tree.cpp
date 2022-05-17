/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
​
class Solution {
public:
    //dfs : 1017ms
    TreeNode* getTargetCopy1(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* result= nullptr;
        function<bool(TreeNode*,TreeNode*)> dfs = [&](TreeNode* node,TreeNode* clone){
            if(!node)
                return false;
            if(node == target)
            {
                result = clone;
                return true;
            }
            if(dfs(node->left,clone->left))
                return true;
            if(dfs(node->right,clone->right))
                return true;
            return false;
        };
        dfs(original,cloned);
            
        return result;
    }
    // bfs : 760ms
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* result= nullptr;
        queue<TreeNode*> q,q1;
        q.push(original);
        q1.push(cloned);
        while(!q.empty()) {
            auto c = q.front();
            auto c1 = q1.front();
            q1.pop();
            q.pop();
            if(c==target)
                return c1;
            if(c->left)
            {
                q.push(c->left);
                q1.push(c1->left);
            }
            if(c->right)
            {
                q.push(c->right);
                q1.push(c1->right);
            }
        }
        return nullptr;
    }
};
