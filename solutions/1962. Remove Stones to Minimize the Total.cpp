class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        int sum=0;
        sum = accumulate(piles.begin(),piles.end(),0);
        for(auto& p:piles)
            q.push(p);
        while(k--){
            int top = q.top();
            q.pop();
            sum -= (top/2);
            q.push(top-(top/2));
        }
        return sum;
    }
};
