class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result(2,0);
        vector<int> count(2,0);
        
        for(auto a:nums)
        {
            if(result[0]==a)
                ++count[0];
            else if(result[1]==a)
                ++count[1];
            else if(!count[0])
            {
                result[0]=a;
                ++count[0];
            }
            else if(!count[1])
            {
                result[1]=a;
                ++count[1];
            }
            else
            {
                --count[0];
                --count[1];
            }
        }
        count[0] = count[1] = 0;
        for (auto a:nums)
          if (result[0]==a)  ++count[0];
          else if (result[1]==a)  ++count[1];
        vector<int> r;
        if (count[0] > nums.size()/3) r.push_back(result[0]);
        if (count[1] > nums.size()/3) r.push_back(result[1]);
        return r;
​
    }
};
