class Solution {
public:
    int maxScore1(string s) {
        int n = s.size();
        auto sum = [](int ss,char c){
            return ss + c - '0';
        };
        int one = accumulate(begin(s),end(s), 0,sum);
        // int one = count(s.begin(), s.end(), '1');  // or this works
        int result = 0;
        int zero=0;
        for(int i=0;i<n-1;++i){
            if(s[i]=='0')
                zero++;
            else
                one--;
            result = max(result,zero + one);
        }
        return result;
    }
    // single pass
    int maxScore(string s) {
        int ones = 0;
        int zeros = 0;
        int best = INT_MIN;
​
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == '1') {
                ones++;
            } else {
                zeros++;
            }
            
            best = max(best, zeros - ones);
        }
        
        if (s[s.size() - 1] == '1') {
            ones++;
        }
        
        return best + ones;
    }
};
