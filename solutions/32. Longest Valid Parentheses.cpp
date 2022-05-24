class Solution {
public:
    // self : 12ms
    int longestValidParentheses1(string s) {
        int n = s.size();
        vector<int> pos;
        int result = 0;
        vector<int> pre(n,0);
        for(int i=0;i<n;++i) {
            if(s[i]=='(')
                pos.push_back(i);
            else {
                if(!pos.empty()) {
                    int l = pos.back();
                    pos.pop_back();
                    int len = i - l +1;
                
                    if(l>0 && pre[l-1]>0)
                        len += pre[l-1];
                    result = max(result,len);
                    pre[i] = len;
                }
            }
        }
        return result;
    }
    // stack : 7ms
    int longestValidParentheses2(string s) {
        stack<int> stk;
        stk.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();i++)
        {
            int t=stk.top();
            if(t!=-1&&s[i]==')'&&s[t]=='(')
            {
                stk.pop();
                maxL=max(maxL,i-stk.top());
            }
            else
                stk.push(i);
        }
        return maxL;
    }
    // dp : 3 ms
    int longestValidParentheses3(string s) {
        int maxans = 0;
        int n = s.size();
        vector<int> dp(n,0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
    // space optimized : 3ms
    int longestValidParentheses(string s) {
        int sum = 0, res = 0, len = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') sum++;
            else sum--;
            if (sum < 0) {
                sum = 0;
                len = 0;
            } else {
                len++;
                if (sum == 0) res = max(res, len);
            }
        }
        sum = 0, len=0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') sum++;
            else sum--;
            if (sum < 0) {
                sum = 0;
                len = 0;
            } else {
                len++;
                if (sum == 0) res = max(res, len);
            }
        }
        return res;
    }
    
};
