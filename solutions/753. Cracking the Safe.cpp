// https://en.wikipedia.org/wiki/De_Bruijn_sequence
class Solution {
public:
    // 16ms : https://leetcode.com/problems/cracking-the-safe/discuss/112966/C%2B%2B-greedy-loop-from-backward-with-explaination
    // An explanation is provided in the solution as to why post order-
    // we'll need to visit in a sort of "post-order", recording the answer after visiting the edge. This is to prevent getting stuck. For example, with k = 2, n = 2, we have the nodes '0', '1'. 
    // If we greedily visit complete edges '00', '01', '10', we will be stuck at the node '0' prematurely. However, if we visit in post-order, we'll end up visiting '00', '01', '11', '10' correctly.
    // Another explanation for preorder - https://leetcode.com/problems/cracking-the-safe/discuss/112966/C++-greedy-loop-from-backward-with-explaination/991570
    string crackSafe1(int n, int k) {
        unordered_set<string> seen;
        string pass(n,'0'),result;
        result += pass;
        seen.insert(pass);
        int count = pow(k,n);
        for(int i=0;i<count;++i)
        {
            string pre = pass.substr(1);
            pre+= to_string(k-1);
            char &c = pre.back();
            for(;c>='0';--c)
            {
                if(!seen.count(pre))
                {
                    seen.insert(pre);
                    result.append(1,c);
                    pass = pre;
                    break;
                }
            }
        }
        return result;
    }
    // https://leetcode.com/problems/cracking-the-safe/discuss/110260/De-Bruijn-sequence-C%2B%2B
    // didnt understand the solution
    string crackSafe2(int n, int k) {
        if (k == 1) return string(n, '0');
        string sequence;
        int v = pow(k,n-1);
        vector<vector<bool> > visited(v,vector(k,false));
        function<void(int)> dfs = [&](int u) 
        {
            for (int i = 0; i < k; ++i) {
                if (!visited[u][i]) {
                    visited[u][i] = true;
                    dfs((u * k + i) % v);
                    sequence.push_back('0' + i);
                }
            }
        };
        dfs(0);
        return sequence + sequence.substr(0, n - 1);
    }
    
    //https://leetcode.com/problems/cracking-the-safe/discuss/153039/DFS-with-Explanations
    // same as first but with failover 
    string crackSafe(int n, int k) {
        int total = pow(k, n);
        string ans(n, '0');
        unordered_set<string> visited = {ans};
        
        function<bool(void)> backtrack =  [&](){
            if(visited.size() == total){
                return true;
            }else{
                for(int i = 0; i < k; ++i){
                    ans.push_back('0'+i);
                    string cur = ans.substr(ans.size()-n);
                    if(visited.find(cur) == visited.end()){
                        visited.insert(cur);
                        if(backtrack()) return true;
                        visited.erase(cur);
                    }
                    ans.pop_back();
                }
                return false;
            }
        };
        
        backtrack();
        return ans;
    }
​
    
    
};
​
