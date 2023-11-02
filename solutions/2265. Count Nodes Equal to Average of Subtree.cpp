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
    int averageOfSubtree(TreeNode* root) {
        int result=0;
        function<pair<int,int>(TreeNode*)> dfs = [&](TreeNode* node) -> pair<int,int>{
            if(!node) return {0,0};
            
            auto [count1, sum1] = dfs(node->left);
            auto [count2, sum2] = dfs(node->right);
            count1 += count2 +1;
            sum1 += sum2 + node->val;
            
            if(node->val == sum1/count1 )
                ++result;
​
            return {count1,sum1};
        };
        dfs(root);
        return result;
    }
};
