class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long result = 0;
        if(cost1<cost2)
            swap(cost1,cost2);
        for(int i=0;i<=total;i+= cost1)
        {
            int k = (total-i)/cost2;
            result += k+1;
        }
        return result;
    }
    // cleaner
    long long waysToBuyPensPencils1(int total, int cost1, int cost2) {
        long long res = 0;
        for (; total >= 0; total -= cost1)
            res += total / cost2 + 1;
        return res;        
    }
};
