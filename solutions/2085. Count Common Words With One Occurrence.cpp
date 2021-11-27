class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> freq1,freq2;
        for(const auto& w:words1)
            freq1[w]++;
        for(const auto& w:words2)
            freq2[w]++;
        int ans = 0;
        for(auto& n: freq1)
        {
            if(n.second == 1 && freq2[n.first]==1)
                ++ans;    
        }
        return ans;
    }
};
