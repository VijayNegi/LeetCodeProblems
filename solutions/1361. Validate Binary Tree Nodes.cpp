class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        set<int> roots;
        for(auto& l:leftChild){
            if(l != -1)
                roots.insert(l);
        }
        for(auto& r:rightChild){
            if(r != -1)
                roots.insert(r);
        }
        
        if(roots.size() != n-1)
            return false;
        int r = -1;
        for(int i=0;i<n;++i)
            if(!roots.count(i)){
                r = i;
                break;
            }
​
        roots.clear();
        function<bool(int i)> dfs = [&](int node){
            if(node == -1) return true;
            if(roots.count(node))
                return false;
            roots.insert(node);
            if(!dfs(leftChild[node]) || !dfs(rightChild[node]))
                return false;
            return true;
        };
​
        return dfs(r) && (roots.size() == n);
        
    }
};
​
