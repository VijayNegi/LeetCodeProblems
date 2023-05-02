class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign=0;
        for(auto& n :nums){
            if(n==0) return 0;
            if(n<0) ++sign;
        }
        return sign%2==1? -1:1;
    }
};
