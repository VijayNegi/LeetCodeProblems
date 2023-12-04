class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        string res;
        for(int i=2;i<n;++i)
            if(num[i]==num[i-1] && num[i]==num[i-2])
                if(!res.size() || res[0] < num[i])
                    res = string(3,num[i]);
​
        return res;
    }
};
