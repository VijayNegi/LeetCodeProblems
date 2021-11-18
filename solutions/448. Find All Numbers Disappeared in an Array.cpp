class Solution {
public:
    //sorting
    vector<int> findDisappearedNumbers1(vector<int>& nums) {
        sort(begin(nums),end(nums));
        vector<int> res;
        int k=0;
        for(int i = 1; i<= nums.size();++i)
        {
            if(k>= nums.size() || nums[k] != i)
                res.push_back(i);
            while(k<nums.size() && nums[k] == i)
                ++k;
        }
        
        return res;
    }
    // hasmap
    vector<int> findDisappearedNumbers2(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();++i)
        {
            s.insert(nums[i]);
        }
        
        vector<int> res;
   
        for(int i = 1; i<= nums.size();++i)
        {
           if(s.count(i))
               continue;
            res.push_back(i);
        }
        
        return res;
    }
    //inplace
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};
