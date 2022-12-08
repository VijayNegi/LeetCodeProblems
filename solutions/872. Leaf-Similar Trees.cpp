        pushLeft(stk2,root2);
        
        while(stk1.size() && stk2.size()){
            TreeNode* one = stk1.back(); 
            TreeNode* two = stk2.back(); 
            if(one->left == nullptr && one->right == nullptr 
               && two->left == nullptr && two->right == nullptr  ){
                if(one->val != two->val)
                    return false;
                stk1.pop_back();
                stk2.pop_back();
            }
            else{
                if(one->left != nullptr || one->right != nullptr){
                    stk1.pop_back();
                    pushLeft(stk1,one->right);
                }
 
                if(two->left != nullptr || two->right != nullptr){
                    stk2.pop_back();
                    pushLeft(stk2,two->right);
                }
            }
        }
        while(stk1.size()){
            TreeNode* one = stk1.back(); stk1.pop_back();
            if(one->left == nullptr && one->right == nullptr )
                return false;
            pushLeft(stk1,one->right);
        }
        while(stk2.size()){
            TreeNode* one = stk2.back(); stk2.pop_back();
            if(one->left == nullptr && one->right == nullptr )
                return false;
            pushLeft(stk2,one->right);
        }
            
        return true;
    }
    
};
