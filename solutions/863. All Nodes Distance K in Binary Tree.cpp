/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        bool found= false;
        unordered_map<TreeNode*,TreeNode*> parent;
        vector<int> result;
        function<void(TreeNode*, TreeNode*, int)> dfs = [&](TreeNode* node,TreeNode* pre,int depth){
            if(!node) return;
            if(node == target) {
                found = true;
                parent[node] = pre;
                pre = nullptr;
            }
            if(!found){
                parent[node] = pre;
                dfs(node->left,node,0);
                if(!found)
                    dfs(node->right,node,0);
            }
            else{
                if(depth== k){
                    result.push_back(node->val);
                    return;
                }
                if(parent[node] && parent[node] !=pre)
                     dfs(parent[node],node,depth+1);
                if(node->left != pre)
                    dfs(node->left,node,depth+1);
                if(node->right != pre)
                    dfs(node->right,node,depth+1);
                
            }
        };
        dfs(root,nullptr,0);
        return result;
    }
};
