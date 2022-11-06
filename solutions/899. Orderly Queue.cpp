class Solution {
public:
    // self: 4 ms
    string orderlyQueue1(string s, int k) {
        int n = s.size();
        string res = s;
        if(k==1){
            string temp = s +s;
            for(int i=0;i<n;++i){
                int flag = false;
                for(int j=i;j<i+n;++j){
                    if(res[j-i] < temp[j])
                        break;
                    else if(res[j-i] > temp[j]){
                        flag = true;
                        break;
                    }
                }
                if(flag){
                    res = temp.substr(i,n);
                }
            }
        }
        else{
            sort(res.begin(),res.end());
        }
        return res;
    }
    // 14 ms
     string orderlyQueue(string S, int K) {
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        string res = S;
        for (int i = 1; i < S.length(); i++)
            res = min(res, S.substr(i) + S.substr(0, i));
        return res;
    }
};
