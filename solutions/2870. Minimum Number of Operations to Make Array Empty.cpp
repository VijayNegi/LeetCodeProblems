class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> count;
        int result=0;
        for(auto& n:nums)
            count[n]++;
        for(auto& [_,c]: count){
            if(c==1) return -1;
            result += c/3;
            if(c%3 !=0)
                ++result;
            // or result += ceil((double)(c) / 3);
        }
        return result;
    }
};
