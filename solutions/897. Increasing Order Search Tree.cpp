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
    TreeNode* increasingBST1(TreeNode* root) {
        vector<TreeNode*> stk;
        function<void(TreeNode*)> pushLefts = [&](TreeNode* node)
        {
            while(node)
            {
                stk.push_back(node);
                node = node->left;
            }
        };
        pushLefts(root);
        TreeNode dummy;
        TreeNode* curr = &dummy;
        while(stk.size())
        {
            TreeNode* node = stk.back();
            stk.pop_back();
            pushLefts(node->right);
            node->left = nullptr;
            curr->right = node;
            curr = node;
        }
        return dummy.right;
    }
    
    TreeNode* increasingBST(TreeNode* root, TreeNode* next=NULL) {
        if(root == NULL) return next;  
        root->right = increasingBST(root->right, next);  
        TreeNode *temp = increasingBST(root->left, root);  
        root->left = NULL; 
        return temp;
    }
    
    TreeNode* increasingBST2(TreeNode* root, TreeNode* tail = NULL) {
        if (!root) return tail;
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};
