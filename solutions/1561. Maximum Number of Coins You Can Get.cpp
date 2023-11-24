class Solution {
public:
    // simulate
    int maxCoins1(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        deque<int> queue;
        for (int num : piles) {
            queue.push_back(num);
        }
        
        int ans = 0;
        while (!queue.empty()) {
            queue.pop_back(); // alice
            ans += queue.back(); // us
            queue.pop_back();
            queue.pop_front(); // bob
        }
        
        return ans;
    }
    // faster
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int ans = 0;
        
        for (int i = piles.size() / 3; i < piles.size(); i += 2) {
            ans += piles[i];
        }
        
        return ans;
    }
};
