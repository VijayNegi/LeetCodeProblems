class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n = s.size();
        string res;
        for(int i=0;i<numRows;++i){
            int j=i;
            while(j<n){
                if(i==0 || i==(numRows-1)){
                    res+=s[j];
                    j+= 2*(numRows-1);
                }
                else{
                    res+=s[j];
                    cout<<s[j];
                    j+= 2*(numRows-i-1);
                    if(j<n)
                        res+=s[j];
                    j+= 2*(i);
                }
            }
        }
        return res;
    }
};
