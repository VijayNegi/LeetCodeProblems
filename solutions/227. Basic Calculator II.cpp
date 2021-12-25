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
​
                if(idx>=n || (op[s[idx]] <= op[oper]))
                {
                    res = doOp(res,b,oper);
                }
                else 
                {
                    
