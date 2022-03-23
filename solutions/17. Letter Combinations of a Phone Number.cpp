class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> m{"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        string s;
        int n = digits.size();
        if(!n)  return result;
        function<void(int)> dfs = [&](int pos)
        {
            if(pos==n)
            {
                result.push_back(s);
                return;
            }
            int i = digits[pos]-'0';
            for(auto ch: m[i])
            {
                s.push_back(ch); //s.append(1,ch);
                dfs(pos+1);
                s.pop_back();
            }
        };
        dfs(0);
        return result;
    }
};
