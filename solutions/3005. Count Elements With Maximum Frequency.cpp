class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> feq(101,0);
        vector<int> count(101,0);
        for(auto& n:nums){
            count[n]++;
            feq[count[n]] += count[n];
        }
        
        for(int i=100;i>=0;--i){
            if(feq[i]) return feq[i];
        }
        return 0;
    }
}; 
