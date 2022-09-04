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
    // self
    vector<vector<int>> verticalTraversal1(TreeNode* root) {
        map<int, vector<int>> result;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int row=0;
        while(!q.empty()){
            map<int, vector<int>> temp;
            int s = q.size();
            for(int i=0;i<s;++i){
                auto [node,col] = q.front();
                q.pop();
                temp[col].push_back(node->val);
                if(node->left)
                    q.push({node->left,col-1});
                if(node->right)
                    q.push({node->right,col+1});
            }
            for(auto& v:temp){
                sort(v.second.begin(),v.second.end());
                result[v.first].insert(result[v.first].end(),v.second.begin(),v.second.end());
            }
              
        }
        vector<vector<int>> res;
        for(auto v:result)
            res.push_back(v.second);
        return res;
    }
    //other impl
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
