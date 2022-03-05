class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> freq;
        
        for(auto& n:nums)
        {
            freq[n]++;
        }
        int d1=0,d2=0;
        int prenum = -2;
        for(auto& it:freq)
        {
           
            int cost =  it.first*it.second;
            if(it.first >(prenum+1))
            {
                cost += max(d2,d1);
            }
            else
            {
                cost += d1; 
                cost = max(cost,d2);
            }
            d1= d2;
            d2=cost;
            prenum = it.first;
        }
        return max(d1,d2);
    }
};
