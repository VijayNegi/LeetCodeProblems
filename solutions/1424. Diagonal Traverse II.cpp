class Solution {
public:
    // TLE
    vector<int> findDiagonalOrder1(vector<vector<int>>& nums) {
        int rows = nums.size();
        int cols = nums[0].size();
        for(auto& v:nums)
            cols = max(cols,(int)v.size());
        vector<int> result;
        int r = 0,c=0;
        while(r<rows && c<cols){
            int r1=r,c1=c;
            while(r1>=0 && c<=cols){
                if(nums[r1].size() > c1 ){
                    result.push_back(nums[r1][c1]);
                }
                --r1,++c1;
            }
            if(r!=rows-1) ++r;
            else ++c;
        }
        return result;
    }
    // grouping
    vector<int> findDiagonalOrder2(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> groups;
        for (int row = nums.size() - 1; row >= 0; row--) {
            for (int col = 0; col < nums[row].size(); col++) {
                int diagonal = row + col;
                groups[diagonal].push_back(nums[row][col]);
            }
        }
        
        vector<int> ans;
        int curr = 0;
        
        while (groups.find(curr) != groups.end()) {
            for (int num : groups[curr]) {
                ans.push_back(num);
            }
            
            curr++;
        }
        
        return ans;
    }
    // bfs
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        vector<int> ans;
        
        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            ans.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) {
                queue.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) {
                queue.push({row, col + 1});
            }
        }
        
        return ans;
    }
};
