class Solution {
public:
    // self : dfs : 14ms
    int maxLength1(vector<string>& arr) {
        int n = arr.size();
        vector<int> mask;
        for(auto& w:arr) {
            int m=0;
            unordered_set<char> s(w.begin(),w.end());
            if(s.size() != w.size()){
                mask.push_back(m);
                continue;
            }
            for(auto& c:w){
                m |= 1<<(c-'a'); 
            }
            mask.push_back(m);
        }
        
        function<int(int,int,int)> dfs = [&](int k, int m, int l){
            int len = l;
            //cout<<"dfs ="<<k<<" "<<m<<" "<<l<<endl;
            while(k<n){
                if(mask[k] && !(m & mask[k])){
                    len = max(len,dfs(k+1,m | mask[k],l+arr[k].size()));
                }
                ++k;
            }
            return len;
        };
        return dfs(0,0,0);
    }
    // set based : 3 ms
    int maxLength(vector<string>& A) {
        vector<bitset<26>> dp = {bitset<26>()};
        int res = 0;
        for (auto& s : A) {
            bitset<26> a;
            for (char c : s)
                a.set(c - 'a');
            int n = a.count();
            if (n < s.size()) continue;
​
            for (int i = dp.size() - 1; i >= 0; --i) {
                bitset c = dp[i];
                if ((c & a).any()) continue;
                dp.push_back(c | a);
                res = max(res, (int)c.count() + n);
            }
        }
        return res;
    }
};
