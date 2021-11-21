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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        function<TreeNode* (int ,int, int&)> helper = [&](int l,int r,int& k) -> TreeNode*
        {
            if(l>r)
                return nullptr;
            int p;
            for(int i=l;i<=r;++i)
            {
                if(inorder[i]==postorder[k])
                {
                    p = i;
                    break;
                }
            }
            --k;
            TreeNode* root = new TreeNode(inorder[p]);
            root->right = helper(p+1,r,k);
            root->left = helper(l,p-1,k);
            return root;
        };
        int s = inorder.size()-1;
        return helper(0,s,s);
    }
};
