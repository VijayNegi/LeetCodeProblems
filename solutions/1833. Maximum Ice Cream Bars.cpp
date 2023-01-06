class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int count=0;
        for(auto& c:costs){
            if(c>coins)
                break;
            coins-=c;
            ++count;
        }
        return count;
    }
};
