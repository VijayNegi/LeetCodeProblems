class Solution {
public:
    int doOp(int a,int b,char op)
    {
        switch(op)
        {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
        }
        return a;
    }
    // first solution
    int calculate1(string s) {
        int n = s.size();
        int idx = 0;
        function<int(string&,int&)> getInt = [](string& s,int& idx)
        {
            if(idx >=s.size())
                return 0;
            int res=0;
            // consume spaces with numbers
            while(s[idx]==' ')
                ++idx;
            while(s[idx]>='0' && s[idx]<='9' )
            {
                res *=10;
                res += s[idx] - '0';
                ++idx;
            }
            // consume spaces with numbers
            while(idx <s.size() && s[idx]==' ')
                ++idx;
            
            return res;
        };
        
        
        unordered_map<char,int> op;
        op['+'] = 1;
        op['-'] = 1;
        op['*'] = 2;
        op['/'] = 2;
        function<int(string&,int&,int)> solve = [&](string& s,int& idx,int opPriority)
        {
            // check next operator , 
            // keep doing operaton while operators have same priority or lower priority,
            // otherwise recursively call sove.
            int n = s.size();
            if(idx>= n)
                return 0;
            int res=getInt(s,idx);
            while(idx<n)
            {
                char oper = s[idx];
                if(op[oper]<=opPriority)
                    break;
                ++idx;
                int tempIdx = idx;
                int b = getInt(s,idx);

                if(idx>=n || (op[s[idx]] <= op[oper]))
                {
                    res = doOp(res,b,oper);
                }
                else 
                {
                    
                    int c = solve(s,tempIdx,op[oper]);
                    res = doOp(res,c,oper);
                    idx = tempIdx;
                }
            }
            return res;
           
        };
        
        return solve(s,idx,0);               
    }
    // other approach: 8ms
    int calculate2(string s) {
        istringstream in('+' + s + '+');
        long long total = 0, term = 0, n;
        char op;
        while (in >> op) {
            if (op == '+' or op == '-') {
                total += term;
                in >> term;
                term *= 44 - op;
            } else {
                in >> n;
                if (op == '*')
                    term *= n;
                else
                    term /= n;
            }
        }
        return total;
    }
    // LC solution : 8ms
     int calculate(string s) { 
         int idx = 0;
         int n = s.size();
         int result = 0;
         int currNum = 0;
         int lastNum = 0;
         char lastOp = '+';
         while(idx<n)
         {
             char c = s[idx++];
             if(isspace(c) && (idx < n))
                 continue;
             if(isdigit(c))
             {
                 currNum *=10;
                 currNum += c - '0';
                 if(idx < n)
                    continue;
             }
             
             if(lastOp=='+'|| lastOp=='-')
             {
                 result += lastNum;
                 lastNum = (lastOp=='+')? currNum:-currNum;;
             }
             else if(lastOp=='*')
                 lastNum *= currNum;
             else if(lastOp=='/')
                 lastNum /= currNum;
            
             currNum=0;
             lastOp = c;
         }
         result += lastNum;
         return result;
     }
};
