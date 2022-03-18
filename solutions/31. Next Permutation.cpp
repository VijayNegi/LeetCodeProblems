class Solution {
public:
    // 7 ms
    void nextPermutation1(vector<int>& nums) {
        int n = nums.size();
        int i=n-2;
        for(i=n-2;i>=0;--i)
        {
            if(nums[i]<nums[i+1])
            {
                int j=i+1;
                for(;j<n;++j)
                    if(nums[j]<=nums[i])
                        break;
                swap(nums[i],nums[j-1]);
                break;
            }
        }
        reverse(begin(nums)+i+1,end(nums));
    }
    // 3 ms
    void nextPermutation2(vector<int>& nums) {
      std::next_permutation(nums.begin(), nums.end());
    }
    // 4 ms : some more STL 
    void nextPermutation(vector<int>& nums) {
      auto dest = std::is_sorted_until(nums.rbegin(), nums.rend());
      if (dest != nums.rend()) {
        auto target = std::upper_bound(nums.rbegin(), dest, *dest);
        std::iter_swap(dest, target);
      }
      std::reverse(nums.rbegin(), dest);
    }
​
};
