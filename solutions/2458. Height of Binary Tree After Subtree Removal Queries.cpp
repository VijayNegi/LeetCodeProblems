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
    // Self TLE, as this is not O(n), Traverse up from node to root
    vector<int> treeQueries1(TreeNode* root, vector<int>& queries) {
        map<TreeNode*,TreeNode*> parent;
        map<int,int> height;
        map<int,TreeNode*> val2Node;
        function<int(TreeNode*,TreeNode*)> getHeight = [&](TreeNode* node,TreeNode* par){
            if(!node) return 0;
            parent[node] = par;
            int l = getHeight(node->left,node);
            int r = getHeight(node->right,node);
            val2Node[node->val] = node;
            height[node->val] = max(l,r)+1;
            return height[node->val];
        };
        getHeight(root,nullptr);
        int m = queries.size();
        vector<int> result;
        for(auto& q:queries){
            int h=0;
            TreeNode* node = parent[val2Node[q]];
            TreeNode* preNode = val2Node[q];
            while(node!=nullptr){
                int t=0;
                if(node->left && node->left != preNode)
                    t = (height[node->left->val]);
                if(node->right  && node->right != preNode)
                    t = (height[node->right->val]);
                h = max(t,h)+1;
                preNode = node;
                node = parent[node];
            }
            result.push_back(h-1);
        }
        return result;
    }
    // code - https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/discuss/2758013/Level-%2B-Depth
    // Explanation https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/discuss/2757990/Python-3-Explanation-with-pictures-DFS
    // O(n) solution
    int level[100001] = {}, depth[100001] = {};
    int d1[100001] = {}, d2[100001] = {};
    int traverse(TreeNode* n, int l = 0) {
        if (n == nullptr)
            return 0;
        level[n->val] = l;
        depth[n->val] = 1 + max(traverse(n->left, l + 1), traverse(n->right, l + 1));   
        if (d1[l] < depth[n->val]) {
            d2[l] = d1[l];
            d1[l] = depth[n->val];
        } 
        else if (d2[l] < depth[n->val])
            d2[l] = depth[n->val];
        return depth[n->val];
    };
    vector<int> treeQueries2(TreeNode* root, vector<int>& queries) {
        traverse(root, 0);
        transform(begin(queries), end(queries), begin(queries), [&](int q){
            int l = level[q];
            return l + (d1[l] == depth[q] ? d2[l] : d1[l]) - 1;
        });
        return queries;
    }
    // Lee Solution - preOrder and postOrder
    // https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/discuss/2759353/C%2B%2BPython-Preoder-and-Postorder-DFS
    int preh[100001], posth[100001], maxh;
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        maxh = 0; pre(root, 0);
        maxh = 0; post(root, 0);
        vector<int> res;
        for (int q : queries)
            res.push_back(max(preh[q], posth[q]));
        return res;
    }

    void pre(TreeNode* root, int h) {
        if (!root) return;
        preh[root->val] = maxh;
        maxh = max(maxh, h);
        pre(root->left, h + 1);
        pre(root->right, h + 1);
    }

    void post(TreeNode* root, int h) {
        if (!root) return;
        posth[root->val] = maxh;
        maxh = max(maxh, h);
        post(root->right, h + 1);
        post(root->left, h + 1);
    }

};
