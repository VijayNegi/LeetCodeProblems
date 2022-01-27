class Solution {
public:
    //understanding - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91050/Python-6-lines-bit-by-bit
    //impl - https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/849128/Python-O(32n)-solution-explained
    int findMaximumXOR(vector<int>& nums) {
        vector<vector<int>> bucket(32);
        int n = nums.size();
        int result=0;
        int mask = 0;
        for(int i=31;i>=0;--i)
        {
            unordered_set<int> st;
            mask |= 1<<i;
            int start = result | 1<<i;
            for(auto a:nums)
            {
                int temp = (a & mask);
                if( st.count(temp^start) )
                {
                    result = start;
                    break;
                }
                st.insert(temp);
            }
        }
        return result;
        
    }
};
​
​
​
