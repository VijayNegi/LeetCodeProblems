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
    // position index wise(Fix overflow , i.e. reset id at each level) :  18 ms
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long,TreeNode*>> q;
        q.push({0,root});
        int level = 1;
        long minw = INT_MAX;
        long maxw = INT_MIN;
        long result = 0;
        long adj = 0;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            --level;
            minw = min(minw,t.first);
            maxw = max(maxw,t.first);
           long id = t.first - adj;
            
            if(t.second->left)
                q.push({id*2 , t.second->left});
            if(t.second->right)
                q.push({id*2+1, t.second->right});
            if(level==0)
            {
                level = q.size();
                result = max(result,abs(maxw-minw)+1);
                if(level)
                    adj = q.front().first;
                minw = INT_MAX;
                maxw = INT_MIN;
            }
        }
        return result;
    }
    // saving childs, TLE
    int widthOfBinaryTree1(TreeNode* root) {
        deque<TreeNode*> q;
        q.push_back({root});
        int level = 1;
        int result = 1;
        bool seen = false;
        while(!q.empty())
        {
            auto t = q.front();
            q.pop_front();
            --level;
           
            if(t)
            {
                q.push_back(t->left);
                q.push_back(t->right);
            }
            else
            {
                q.push_back(nullptr);
                q.push_back(nullptr);
            }
            
            if(level==0)
            {
                while(q.size() && q.front()== nullptr)
                    q.pop_front();
                while(q.size() && q.back()== nullptr)
                    q.pop_back();
                
                result = max(result,level);
            }
        }
        return result;
    }
};
