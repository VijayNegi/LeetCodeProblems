class Solution {
public:
    vector<string> restoreIpAddresses1(string s) {
        int dots=0, n = s.size();
        vector<string> result;
        function<void(string,int )> dfs = [&](string c,int p){
            if(p==n && dots==4){
                c.pop_back();
                result.push_back(c);
                return;
            }
            if(p==n || dots==4) return;
        
            int i=0,num=0;
            while(i<3 && (i+p)<n){
                if(i>0 && num==0) break;
                num = num*10 + s[i+p]-'0';
                if(num>255 ) break;
                c+= s[i+p];
                ++dots;
                dfs(c+".",i+p+1);
                --dots;
                ++i;
            }
        };
        dfs("",0);
        return result;
    }
        vector<string> restoreIpAddresses(string s) {
        vector<string> ret;
        string ans;
        
        for (int a=1; a<=3; a++)
        for (int b=1; b<=3; b++)
        for (int c=1; c<=3; c++)
        for (int d=1; d<=3; d++)
            if (a+b+c+d == s.length()) {
                int A = stoi(s.substr(0, a));
                int B = stoi(s.substr(a, b));
                int C = stoi(s.substr(a+b, c));
                int D = stoi(s.substr(a+b+c, d));
                if (A<=255 && B<=255 && C<=255 && D<=255)
                    if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                        ret.push_back(ans);
            }    
        
        return ret;
    }
};
