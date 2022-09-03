class Solution {
public:
    // self : 9ms
    vector<int> numsSameConsecDiff1(int n, int k) {
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
    // 3 ms
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= N; ++i) {
            vector<int> cur2;
            for (int x : cur) {
                int y = x % 10;
                if (y + K < 10)
                    cur2.push_back(x * 10 + y + K);
                if (K > 0 && y - K >= 0)
                    cur2.push_back(x * 10 + y - K);
            }
            cur = cur2;
        }
        return cur;
    }
};
