class Solution {
public:
    // self 185ms
    int garbageCollection1(vector<string>& garbage, vector<int>& travel) {
        int n = travel.size();
        function<int(char)> collectionTime = [&](char c){
            int currentCost=0;
            int finalCost = 0;
            for(int i=0;i<=n;++i){
                int num_items = std::count(garbage[i].begin(), garbage[i].end(), c);
                if(num_items){
                    currentCost+=num_items;
                    finalCost = currentCost;
                }
                if(i<n)
                    currentCost += travel[i];
            }
            return finalCost;
        };
        int result = collectionTime('M');
        result += collectionTime('P');
        result += collectionTime('G');
        return result;
    }
    // other solution from commetns 154ms
    int garbageCollection2(vector<string>& garbage, vector<int>& travel) {
        int len = garbage.size();
        int res = 0;
        unordered_set<char> s;
        for (int i = len - 1; i >= 0 ; i--) {
            for (char ch : garbage[i]) 
                if (!s.count(ch)) 
                    s.insert(ch);
​
            res += garbage[i].length();
            res += i > 0 ? s.size() * travel[i - 1] : 0;
        }
​
        return res;
    }
    // offical solution 198ms
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // Store the prefix sum in travel itself.
        for (int i = 1; i < travel.size(); i++) {
            travel[i] = travel[i - 1] + travel[i];
        }
        
        // Map to store garbage type to the last house index.
        unordered_map<char, int> garbageLastPos;
        int ans = 0;
        for (int i = 0; i < garbage.size(); i++) {
            for (char c : garbage[i]) {
                garbageLastPos[c] = i;
            }
            ans +=  garbage[i].size();
        }
        
        string garbageTypes = "MPG";
        for (char c : garbageTypes) {
            // No travel time is required if the last house is at index 0.
            ans += (garbageLastPos[c] == 0 ? 0 : travel[garbageLastPos[c] - 1]);
        }
        
        return ans;
    }
};
