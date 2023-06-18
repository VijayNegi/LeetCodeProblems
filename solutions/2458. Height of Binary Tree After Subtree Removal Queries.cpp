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
​
    void pre(TreeNode* root, int h) {
        if (!root) return;
        preh[root->val] = maxh;
        maxh = max(maxh, h);
        pre(root->left, h + 1);
        pre(root->right, h + 1);
    }
​
    void post(TreeNode* root, int h) {
        if (!root) return;
        posth[root->val] = maxh;
        maxh = max(maxh, h);
        post(root->right, h + 1);
        post(root->left, h + 1);
    }
​
};
