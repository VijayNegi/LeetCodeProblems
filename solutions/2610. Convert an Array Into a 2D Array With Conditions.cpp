class Solution {
public:
    // self
    vector<vector<int>> findMatrix1(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int,int> count;
        for(auto& n:nums)
            count[n]++;
        
        while(true){
            vector<int> temp;
            for(auto& n:count){
                if(n.second){
                    temp.push_back(n.first);
                    n.second--;
                }
            }
            if(temp.size()==0)
                break;
            result.push_back(temp);
        }
        return result;
    }
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<int> freq(nums.size() + 1);
        
        vector<vector<int>> ans;
        for (int c : nums) {
            if (freq[c] >= ans.size()) {
                ans.push_back({});
            }
            
            // Store the integer in the list corresponding to its current frequency.
            ans[freq[c]].push_back(c);
            freq[c]++;
        }
        
        return ans;
    }
};
