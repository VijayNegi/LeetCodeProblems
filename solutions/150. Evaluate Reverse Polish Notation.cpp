class Solution {
public:
    int evalRPN1(vector<string>& tokens) {
        vector<long> stk;
        for(auto& t:tokens){
            if(t.size()==1 && (t[0]=='+'|| t[0]=='-' || t[0]=='*' || t[0]=='/')){
                int op1 = stk.back(); stk.pop_back();
                int op2 = stk.back(); stk.pop_back();
                stk.push_back(operate(t[0],op2,op1));
            }
            else{
                stk.push_back(stoi(t));
            }  
        }
        return stk.back();
    }
    long operate(char op,long a,long b){
        switch(op)
        {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '/':
                return a/b;
            case '*':
                return a*b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long> stk;
        
        for(const auto s:tokens)
        {
            if(s!="+" && s!="-" && s!="/" && s!="*")
                stk.push(std::stoi(s));
            else
            {
                long a = stk.top(); stk.pop();
                long b = stk.top(); stk.pop(); 
                switch(s[0])
                {
                    case '+': stk.push(a+b);
                        break;
                    case '-': stk.push(b-a);
                        break;
                    case '*': stk.push(a*b);
                        break;
                    case '/':stk.push(b/a);
                        break;
                }
            }
        }
        return stk.top();
    }
};
