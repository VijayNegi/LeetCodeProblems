class Solution {
public:
    int calculate1(string s) {
        int n = s.size();
        function<int(string&,int&)> dfs = [&](string& s, int& pos){
            int result=0;
            int curr=0;
            int sign = 1;
            while(pos<n){
                char c = s[pos];
                if(isdigit(c)){
                    curr = curr*10 + (c-'0');
                }
                else if(c=='-' || c=='+'){
                    result += curr*sign;
                    sign = (c=='-')? -1:1;
                    curr=0;
                }
                else if(c=='(' || c==')'){
                    result += curr*sign;
                    if(c=='(' )
                        curr = dfs(s,++pos);
                    else{
                        return result;
                    }
                }
                ++pos;
            }
            result += curr*sign;
            return result;
        };
        int pos = 0;
        return dfs(s,pos);
    }
    // stack based
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + ( c - '0');
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
    }

};
