class Solution {
public:
    // self : 9ms
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        function<void(string)> dfs = [&](string s) {
            if(s.size()==n){
                if(s[0]=='0')
                    return;
                result.push_back(stoi(s));
                return;
            }
                
            int last = s[0]-'0';
            if(last+k < 10) {
                dfs(to_string(last+k)+s);
            }
            if((last-k)>=0 && k!=0) {
                dfs(to_string(last-k)+s);
            }   
        };
        for(int i=0;i<10;++i){
            dfs(to_string(i));
        }
        return result;
    }
};
