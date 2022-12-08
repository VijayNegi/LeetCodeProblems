/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool leafSimilar1(TreeNode* root1, TreeNode* root2) {
        vector<TreeNode*> stk1,stk2;
        function<void(vector<TreeNode*>&, TreeNode*)> pushLeft = [](vector<TreeNode*>& stk, TreeNode* node) {
            while(node){
                stk.push_back(node);
                node = node->left;
            }
        };
        pushLeft(stk1,root1);
        pushLeft(stk2,root2);
        
        while(stk1.size() && stk2.size()){
            TreeNode* one = stk1.back(); 
            TreeNode* two = stk2.back(); 
            if(one->left == nullptr && one->right == nullptr 
               && two->left == nullptr && two->right == nullptr  ){
                if(one->val != two->val)
                    return false;
                stk1.pop_back();
                stk2.pop_back();
            }
            else{
                if(one->left != nullptr || one->right != nullptr){
                    stk1.pop_back();
                    pushLeft(stk1,one->right);
                }
 
                if(two->left != nullptr || two->right != nullptr){
                    stk2.pop_back();
                    pushLeft(stk2,two->right);
                }
            }
        }
        while(stk1.size()){
            TreeNode* one = stk1.back(); stk1.pop_back();
            if(one->left == nullptr && one->right == nullptr )
                return false;
            pushLeft(stk1,one->right);
        }
        while(stk2.size()){
            TreeNode* one = stk2.back(); stk2.pop_back();
            if(one->left == nullptr && one->right == nullptr )
                return false;
            pushLeft(stk2,one->right);
        }
            
        return true;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1;
        vector<int> leaves2;
        dfs(root1, leaves1);
        dfs(root2, leaves2);

        return leaves1 == leaves2;
    }

    void dfs(TreeNode* node, vector<int>& leaves) {
        if (node == NULL) return;
        if (node->left == NULL && node->right == NULL)
            leaves.push_back(node->val);
        dfs(node->left, leaves);
        dfs(node->right, leaves);
    }
    
};
