class Solution {
public:
    int minOperations1(string s) {
        int n = s.size();
        int result = 0;
        for(int i=0;i<n;++i){
            if( (i%2) && s[i]!='1')
                ++result;
            else if((i%2)==0 && s[i]!='0')
                ++result; 
        }
        int res1=0;
        for(int i=0;i<n;++i){
            if((i%2) && s[i]!='0')
                ++res1; 
            else if((i%2)==0 && s[i]!='1')
                ++res1; 
        }
        return min(result,res1);
    }
    int minOperations(string s) {
        int n = s.size();
        int result = 0;
        for(int i=0;i<n;++i){
            if( (i%2) && s[i]!='1')
                ++result;
            else if((i%2)==0 && s[i]!='0')
                ++result; 
        }
        return min(result,n-result);
    }
};
