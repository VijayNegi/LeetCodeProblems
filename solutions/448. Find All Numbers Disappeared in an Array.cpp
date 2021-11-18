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
    
    vector<int> findDisappearedNumbers(vector<int>& nums) {
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
};
