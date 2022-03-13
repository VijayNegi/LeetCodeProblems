class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(const auto& c:s)
        {
            if(c =='(' || c=='{' || c=='[')
            {
                if(c=='(')
                    stk.push(')');
                else if(c=='{')
                    stk.push('}');
                else
                    stk.push(']');
            }
            else
            {
                if(!stk.empty() && stk.top()==c)
                {
                    stk.pop();
                }
                else
                    return false;
            }
        }
        if(stk.empty())
            return true;
        return false;
    }
};
