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
    // TLE
    int widthOfBinaryTree1(TreeNode* root) {
        vector<TreeNode*> q;
        q.push_back(root);
        int res = 0;
        while(q.size()){
            res = max(res,(int)q.size());
            vector<TreeNode*> t;
            for(auto& node:q){
                if(!node && t.size()){
                    t.push_back(nullptr);
                    t.push_back(nullptr);
                }
                else if(node){
                    if(node->left || t.size())
                        t.push_back(node->left);
                    if(node->right || t.size())
                        t.push_back(node->right);
                }
            }
            while(!t.empty() && !t.back())
                t.pop_back();
            swap(q,t);
        }
        return res;
    }
};
