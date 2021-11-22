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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return nullptr;
        if(root->val == key)
        {
            if(root->right == nullptr)
                return root->left;
            else if(root->left == nullptr)
                return root->right;
            
            // get minimum node from right subtree
            if(root->right->left)
            {
                TreeNode* pre = root;
                TreeNode* curr = root->right;
                while(curr->left)
                {
                    pre = curr;
                    curr = curr->left;
                }
                // Remove min node
                pre->left = curr->right;
                root->val = curr->val;
            }
            else
            {
                root->val = root->right->val;
                root->right = root->right->right;
            }
            //delete curr;
        }
        else
        {
            if(key < root->val)
                root->left = deleteNode(root->left,key);
            else
                root->right = deleteNode(root->right,key);
        }
        return root;
    }
    
};
