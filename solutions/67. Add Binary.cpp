class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        
        reverse(begin(a),end(a));
        reverse(begin(b),end(b));
        
        int sum=0;
        int i=0;
        while(i<a.size() ||  i<b.size())
        {
            if(i<a.size())
                sum += (a[i]=='1');
            if(i<b.size())
                sum += (b[i]=='1');
            if(sum%2)
                res.push_back('1');
            else
                res.push_back('0');
            sum = sum/2;
            ++i;
        }
        if(sum)
            res.push_back('1');
        
        reverse(begin(res),end(res));
        return res;
    }
};
