        {
            int n = q.front();
            q.pop();
            //cout<<n<<endl;
            if(!(NodeList[n]))
                continue;
            if(childs[n].first != -1)
            {
                NodeList[n]->left = NodeList[childs[n].first];
                q.push(childs[n].first);
                    
            }
            if(childs[n].second != -1)
            {
                NodeList[n]->right = NodeList[childs[n].second];
                q.push(childs[n].second);
            }
        }
        return NodeList[0];
    }
#endif
    //Recursive preorder 
    string serialize(TreeNode* root) 
    {
        return !root ? " #" : " " + to_string(root->val) + serialize(root->left) + serialize(root->right);
    }
   
     TreeNode* deserialize(string data) 
    {
        istringstream ss(data);
        return buildTree(ss);
    }
private:
    TreeNode* buildTree(istringstream& ss)
    {
        string s;
        ss >> s;
        
        if (s == "#")
            return nullptr;
        
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
            
        return node;
    }
    
};
​
// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
