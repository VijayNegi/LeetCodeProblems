class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> stk;
        
        for(auto& s:ops)
        {
            if(s  == "+")
            {
                int n = stk.back();
                n += stk[stk.size()-2];
                stk.push_back(n);
            }
            else if(s == "D")
            {
                int n = stk.back();
                stk.push_back(n*2);
            }
            else if(s == "C")
            {
                stk.pop_back();
            }
            else
                stk.push_back(stoi(s));
        }
        
        int sum = accumulate(begin(stk),end(stk),0);
        return sum;
    }
};
