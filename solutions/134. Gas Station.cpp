class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tcost = std::accumulate(cost.begin(), cost.end(), 0);
        int tgas = std::accumulate(gas.begin(), gas.end(), 0);
        if(tgas<tcost)
            return -1;
        int n = gas.size();
        int index = 0;
        int sum = 0;
        int minSum = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int mi=i%gas.size();
            int temp = gas[mi]-cost[mi];
            sum +=temp;
            if(sum<=minSum)
            {
                minSum = sum;
                index = mi;
            }
        }
        return (index+1)%n;
    }
};
