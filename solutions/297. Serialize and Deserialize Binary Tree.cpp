/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
#if 0 // my Idx solution
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "";
        queue<pair<int,TreeNode*>> q;
        string result;
        int idx = 0;
        q.push({idx++,root});
        
        while(q.size())
        {
            auto p = q.front();
            q.pop();
            result +="|"+ to_string(p.first) + "|" + to_string(p.second->val) + "|"+ to_string(idx) + "|"  + to_string(idx+1);
            idx +=2;
            if(p.second->left)
                q.push({idx-2,p.second->left});
            if(p.second->right)
                q.push({idx-1,p.second->right});
        }
        result  = to_string(idx) + result;
        //cout<<result<<endl;
        return result;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //cout<<data<<endl;
        if(data.empty())
            return nullptr;
        
        stringstream ss(data);
        string ssize;
        getline(ss,ssize, '|');
        int size = stoi(ssize);
        
        vector<TreeNode*> NodeList(size,nullptr);
        vector<pair<int,int>> childs(size,{-1,-1});
       
        while(true)
        {
            string line;
            int idx,val,lchild,rchild; 
            getline(ss,line, '|');
            if(line.empty())
                break;
            idx = stoi(line);
            //cout<<idx<<endl;
            getline(ss,line, '|');
            val = stoi(line);
            getline(ss,line, '|');
            lchild = stoi(line);
            getline(ss,line,'|');
            rchild = stoi(line);
            TreeNode* node = new TreeNode(val);
            NodeList[idx] = node;
            childs[idx]  = {lchild,rchild};
            //cout<<idx<<" "<<val<<" "<<lchild<<" "<<rchild<<endl;
        }
        queue<int> q;
        q.push(0);
        while(!q.empty())
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

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
