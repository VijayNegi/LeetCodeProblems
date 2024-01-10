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
    int amountOfTime(TreeNode* root, int start) {
        int result=0;
        function<void(TreeNode*,int&,int& )> dfs = [&](TreeNode* node,int& d2s,int& d2l){
            if(!node) return;
            if(node->val == start) d2s = 0;
            if(!node->left && !node->right){
                d2l = 0;
                return;
            }
            int ld2s,ld2l,rd2s,rd2l;
            rd2s = ld2s = -1;
            ld2l=rd2l=-1;
            dfs(node->left,ld2s,ld2l);
            dfs(node->right,rd2s,rd2l);
            d2l = max( ld2l , rd2l);
            d2l++;
            if(d2s==0){ // node itself is start
                result = max(result, d2l);
            }
            if(ld2s>=0){ // start at left side
                result = max(result, ld2s + rd2l+2);
                d2s = ld2s +1;
            }
            if(rd2s>=0){ // start at right side
                result = max(result, rd2s + ld2l+2);
                d2s = rd2s +1;
            }
        };
        
        int a,b,c,d;
        a=b=c=d = -1;
        dfs(root,a,b);
        return result;
    }
};
