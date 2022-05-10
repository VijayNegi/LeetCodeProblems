class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        
        vector<bool> mp(10,false);
        function<void(int,int,vector<int>&)> dfs = [&](int digit,int sum,vector<int>& curr) {
            if(sum == 0 && curr.size()==k)
            {
                result.push_back(curr);
                return;
            }   
            if(sum <=0 || digit >= 10 || curr.size() >=k )
                return;
            dfs(digit+1,sum,curr);
            sum -= digit;
            curr.push_back(digit);
            dfs(digit+1,sum,curr);
            curr.pop_back();
        };
        vector<int> res;
        dfs(1,n,res);
        return result;
    }
};
