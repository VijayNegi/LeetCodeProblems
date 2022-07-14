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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        function<TreeNode*(int,int,int,int)> dfs = [&](int pl,int pr,int il,int ir) -> TreeNode* {
            if(pr<pl || ir<il)
                return nullptr;
            TreeNode* root = new TreeNode(preorder[pl]);
            if(pl==pr)
                return root;
            int mid=il;
            for(;mid<=ir;++mid) {
                if(inorder[mid] == preorder[pl])
                    break;
            }
            int len = mid-il;
            root->left = dfs(pl+1,pl+len,il,mid-1);
            root->right = dfs(pl+len+1,pr,mid+1,ir);
            return root;
        };
        return dfs(0,preorder.size()-1,0,inorder.size()-1);
    }
};
