class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int n = pushed.size();
        int pu,po;
        pu=po=0;
        while(pu<pushed.size() && po<popped.size())
        {
            while(!stk.empty())
            {
                if(stk.top() == popped[po])
                {
                    stk.pop();
                    po++;
                }
                else
                    break;
            }
            stk.push(pushed[pu++]);  
        }
        
        while(!stk.empty())
        {
                if(stk.top() == popped[po])
                {
                    stk.pop();
                    po++;
                }
                else
                    break;
        }
        
        return stk.empty() && (pu>=n);
    }
};
