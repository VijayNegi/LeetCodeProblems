class Solution {
public:
    int scoreOfParentheses1(string s) {
        int idx=0;
        return score(s,idx)/2;
    }
    // 5 ms : mine
    int score(string& s, int& idx)
    {
        if(idx == s.size())
            return 0;
        
        int result = 0;
        while(idx < s.size())
        {
            if(s[idx]==')')
            {
                ++idx;
                break;
            }
            else 
            {
                result += score(s,++idx);
            }
        }
        return result==0?1:2*result;
    }
    
    int scoreOfParentheses2(string S) {
        stack<int> stack;
        int cur = 0;
        for (char i : S)
            if (i == '(') {
                stack.push(cur);
                cur = 0;
            }
            else {
                cur += stack.top() + max(cur, 1);
                stack.pop();
            }
        return cur;
    }
    // https://leetcode.com/problems/score-of-parentheses/discuss/141777/C%2B%2BJavaPython-O(1)-Space
    // more exp - https://leetcode.com/problems/score-of-parentheses/discuss/1080518/Python-O(1)-space-solution-explained
     int scoreOfParentheses(string S) {
        int res = 0, l = 0;
        for (int i = 0; i < S.length(); ++i) {
            if (S[i] == '(') l++; else l--;
            if (S[i] == ')' && S[i - 1] == '(') res += 1 << l;
        }
        return res;
    }
​
};
