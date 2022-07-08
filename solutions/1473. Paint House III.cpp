class Solution {
    const int MAX_COST = 1000001;
public:
    // top down approach :154 ms
    int minCost1(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int memo[100][100][21];
        // Maximum cost possible plus 1
        
        memset(memo, -1, sizeof(memo));
        function<int(int,int,int)> dfs = [&](int h,int k,int c) { // h-house no, k- neighbour count, c- previous house color
            if(h == m)
                return k == target? 0 : MAX_COST;
            if(k>target) 
                return MAX_COST;
            if(memo[h][k][c] != -1)
                return memo[h][k][c];
            int minCost = MAX_COST;
            if(houses[h]) {
                int newK = k + (houses[h] != c);
                minCost = dfs(h+1,newK,houses[h]);
            } else {
                for(int color=1;color<= n;++color) {
                    int newK = k + (color != c);
                    int currCost = cost[h][color-1] + dfs(h+1,newK,color);
                    minCost = min(minCost,currCost);
                }
            }
            return memo[h][k][c] = minCost;
        };
        int result = dfs(0,0,0);
        return result == MAX_COST? -1: result;
    }
    // bottom up :146 ms
    int minCost2(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(target + 1, vector<int>(n, MAX_COST)));
        // Initialize for house 0, neighborhoods will be 1
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) { 
                memo[0][1][color - 1] = 0;  // If the house has same color, no cost
            } else if (!houses[0]) {
                memo[0][1][color - 1] = cost[0][color - 1];      // If the house is not painted, assign the corresponding cost
            }
        }
        
        for (int house = 1; house < m; house++) {
            for (int neighborhoods = 1; neighborhoods <= min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    // If the house is already painted, and color is different
                    if (houses[house] && color != houses[house]) {
                        // Cannot be painted with different color
                        continue;
                    }
 
                    int currCost = MAX_COST;
                    // Iterate over all the possible color for previous house
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            // Decrement the neighborhood as adjacent houses has different color
                            currCost = min(currCost, memo[house - 1][neighborhoods - 1][prevColor - 1]);
                        } else {
                            // Previous house has the same color, no change in neighborhood count
                            currCost = min(currCost, memo[house - 1][neighborhoods][color - 1]);
                        }
                    }
                    // If the house is already painted cost to paint is 0
                    int costToPaint = houses[house] ? 0 : cost[house][color - 1];
                    memo[house][neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
        }
        
        int minCost = MAX_COST;
        // Find the minimum cost with m houses and target neighborhoods
        // By comparing cost for different color for the last house
        for (int color = 1; color <= n; color++) {
            minCost = min(minCost, memo[m - 1][target][color - 1]);
        }
        // Return -1 if the answer is MAX_COST as it implies no answer possible
        return minCost == MAX_COST ? -1 : minCost;
    }
    // bottom up (space optimized) : 120ms
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // Initialize prevMemo array
        vector<vector<int>> prevMemo(target + 1, vector<int>(n, MAX_COST));
        // Initialize for house 0, neighborhood will be 1
        for (int color = 1; color <= n; color++) {
            if (houses[0] == color) {
                // If the house has same color, no cost
                prevMemo[1][color - 1] = 0;
            } else if (!houses[0]) {
                // If the house is not painted, assign the corresponding cost
                prevMemo[1][color - 1] = cost[0][color - 1];
            }
        }
        for (int house = 1; house < m; house++) {
            vector<vector<int>> memo(target + 1, vector<int>(n, MAX_COST));
            
            for (int neighborhoods = 1; neighborhoods <= min(target, house + 1); neighborhoods++) {
                for (int color = 1; color <= n; color++) {
                    // If the house is already painted, and color is different
                    if (houses[house] && color != houses[house]) {
                        continue;     // Cannot be painted with different color
                    }
 
                    int currCost = MAX_COST;
                    // Iterate over all the possible color for previous house
                    for (int prevColor = 1; prevColor <= n; prevColor++) {
                        if (prevColor != color) {
                            // Decrement the neighborhood as adjacent houses has different color
                            currCost = min(currCost, prevMemo[neighborhoods - 1][prevColor - 1]);
                        } else {
                            // Previous house has the same color, no change in neighborhood count
                            currCost = min(currCost, prevMemo[neighborhoods][color - 1]);
                        }
                    }

                    // If the house is already painted cost to paint is 0
                    int costToPaint = houses[house] ? 0 : cost[house][color - 1];
                    memo[neighborhoods][color - 1] = currCost + costToPaint;
                }
            }
            // Update the table to have the current house results
            prevMemo = memo;
        }
        
        int minCost = MAX_COST;
        // Find the minimum cost with m houses and target neighborhoods
        // By comparing cost for different color for the last house
        for (int color = 1; color <= n; color++) {
            minCost = min(minCost, prevMemo[target][color - 1]);
        }
        return minCost == MAX_COST ? -1 : minCost;
    }
};
