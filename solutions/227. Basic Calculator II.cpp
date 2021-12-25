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
