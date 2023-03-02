class Solution {
public:
    int compress(vector<char>& chars) {
        int l,r,n=chars.size();
        l=r=0;
        while(r<n){
            int k=r+1;
            while(k<n && chars[k]==chars[r])
                ++k;
            chars[l++]= chars[r];
            if(k-r>1){
                string s = to_string(k-r);
                for(auto& c:s){
                    chars[l++] = c;
                }
            }
            r = k;
        }
        
        return l;
    }
};
