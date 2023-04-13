class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> stk;
        int i=0,j=0;
        while(i<n || j<n){
            if(j<n && stk.size() && stk.top() == popped[j]){
                stk.pop();
                ++j;
            }
            else if(i<n){
                stk.push(pushed[i]);
                ++i;
            }
            else break;
        }
        return i==n && j==n;
    }
};
