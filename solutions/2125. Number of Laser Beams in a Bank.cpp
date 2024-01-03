class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int pre=0;
        int result=0;
        for(auto& s:bank){
            int curr=0;
            for(auto& c:s) if(c=='1') ++curr;
            if(curr){
                result += pre*curr;
                pre = curr;
            }
        }
        return result;
    }
};
