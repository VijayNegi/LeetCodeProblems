class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = accumulate(cardPoints.begin(), cardPoints.begin()+k,0);
        int result = sum;
        int n = cardPoints.size();
        if(n==k)
            return result;
        for(int i=1;i<=k;++i) {
            sum += cardPoints[n-i] - cardPoints[k-i];
            result = max(result,sum);
        }
        return result;
    }
};
