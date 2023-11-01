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
    vector<int> findMode1(TreeNode* root) {
        unordered_map<int,int> freq;
        int max_count=0;
        vector<int> result;
        function<void(TreeNode*)> dfs = [&](TreeNode* node){
            if(!node) return;
            freq[node->val]++;
            if(freq[node->val]>max_count){
                max_count = freq[node->val];
                result.clear();
                result.push_back(node->val);
            }
            else if(freq[node->val] == max_count){
                result.push_back(node->val);
            }
            dfs(node->left);
            dfs(node->right);
        };
        dfs(root);
        return result;
    }
    // without hash table, inorder traversal
    vector<int> ans;
    int maxStreak = 0;
    int currStreak = 0;
    int currNum = 0;
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return ans;
    }
    
    void dfs(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
​
        dfs(node->left);
        
        int num = node->val;
        if (num == currNum) {
            currStreak++;
        } else {
            currStreak = 1;
            currNum = num;
        }
​
        if (currStreak > maxStreak) {
            ans = {};
            maxStreak = currStreak;
        }
​
        if (currStreak == maxStreak) {
            ans.push_back(num);
