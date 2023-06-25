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
    // binary search
    bool twoSumBSTs1(TreeNode* root1, TreeNode* root2, int target) {
        if(!root1 || !root2) return false;
        function<bool(TreeNode*,int)> find = [&](TreeNode* node,int t){
            if(!node) return false;
            if(node->val == t) return true;
            if(node->val < t) return find(node->right,t);
            return find(node->left,t);
        };
        if(find(root2,target - root1->val))
            return true;
        return twoSumBSTs(root1->left,root2,target) or twoSumBSTs(root1->right,root2,target);
    }
    // stack
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        if (!root1 || !root2) {
            return false;
        }
        stack<TreeNode*> s1, s2;
        s1.push(root1);
        s2.push(root2);
        root1 = root1->left;
        root2 = root2->right;
        while (!s1.empty() && !s2.empty() || root1 || root2) {
            while (root1) {
                s1.push(root1);
                root1 = root1->left;
            }
            while (root2) {
                s2.push(root2);
                root2 = root2->right;
            }          
            int sum = s1.top()->val + s2.top()->val;
            if (sum == target) {
                return true;
            } else if (sum > target) {
                root2 = s2.top()->left;
                s2.pop();
            } else {  // sum < target
                root1 = s1.top()->right;
                s1.pop();
            }
        }
        return false;
    }
};
