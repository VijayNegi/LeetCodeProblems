class Solution {
public:
    int longestValidParentheses(string s) {
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
};
