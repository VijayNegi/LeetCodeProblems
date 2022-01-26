            if(!node)
                return;
            ascTrees(node->left,asc);
            asc.push_back(node->val);
            ascTrees(node->right,asc);
        };
        
        vector<int> t1,t2;
        ascTrees(root1,t1);
        ascTrees(root2,t2);
        
        int i1=0,i2=0;
        while(i1<t1.size() && i2<t2.size())
        {
            if(t1[i1]<=t2[i2])
                res.push_back(t1[i1++]);
            else 
                res.push_back(t2[i2++]);
        }
        
        if(i1<t1.size())
            res.insert(res.end(),t1.begin()+i1,t1.end());
        if(i2<t2.size())
            res.insert(res.end(),t2.begin()+i2,t2.end());
        return res;
    }
    
    //stack solution
    void pushLeft(stack<TreeNode*> &s, TreeNode* n) {
        while (n != nullptr) 
            s.push(exchange(n, n->left));
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        stack<TreeNode*> s1, s2;
        pushLeft(s1, root1);
        pushLeft(s2, root2);
        while (!s1.empty() || !s2.empty()) {
            stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : 
                s1.top()->val < s2.top()->val ? s1 : s2;
            auto n = s.top(); s.pop();
            res.push_back(n->val);
            pushLeft(s, n->right);
        }
        return res;
    }
};
