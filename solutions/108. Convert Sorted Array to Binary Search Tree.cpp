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
    TreeNode* treeBuilder(vector<int>& nums,int s,int e)
    {
        int len = e-s;
        if(len<0)
            return nullptr;
        if(len==0)
            return new TreeNode(nums[s]);
        
        int mid = s + len/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = treeBuilder(nums,s,mid-1);
        root->right = treeBuilder(nums,mid+1,e);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return treeBuilder(nums,0,nums.size()-1);
        
    }
};
