        
        vector<int> positions;
        vector<int> prefix;
        int curr = 0;
        for (auto& pair : difference) {
            positions.push_back(pair.first);
            curr += pair.second;
            prefix.push_back(curr);
        }
        
        vector<int> ans;
        for (int person : people) {
            int i = upper_bound(positions.begin(), positions.end(), person) - positions.begin() - 1;
            ans.push_back(prefix[i]);
        }
        
        return ans;
    }
    // simple binary search
    // 227 ms
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        
        for (vector<int>& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1] + 1);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> ans;
        
        for (int person : people) {
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin();
            ans.push_back(i - j);
        }
        
        return ans;
    }
};
