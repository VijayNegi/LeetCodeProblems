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
    // 33 ms
    int minCameraCover1(TreeNode* root) {
        int result=0;
        
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if(!node)
                return 0;
            int left = dfs(node->left);
            int right = dfs(node->right);
            if(left==1 || right==1) {
                ++result;
                return 2;
            }
            if(left==2 || right==2)
                return 0;
            return 1;
        };
        if(dfs(root)==1)
            ++result;
        return result;
    }
    // old, 18ms
    int minCameraCover(TreeNode* root) {
        int cam=0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            int depth=0,depthR=1,depthL=1;
            if(node->right)
                depthR = dfs(node->right);
            if(node->left)
                depthL = dfs(node->left);
            depth = max(depthL, depthR);
            if(depth >= 2) {
                cam++;
                return 0; // reset depth to 0;
            }
            depth = min(depthL,depthR);
            if(depth<=1) // 0
                ++depth;
            return depth;
        };
        if(dfs(root)>1)
            cam++;
        return cam;
    }
};
​
