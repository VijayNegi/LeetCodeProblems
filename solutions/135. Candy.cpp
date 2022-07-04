class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n,1);
        for(int i=0;i<n-1;++i) {
            if(ratings[i+1]>ratings[i])
                candies[i+1] = max(candies[i+1],candies[i]+1);
        }
        for(int i=n-1;i>0;--i) {
            if(ratings[i-1]>ratings[i])
                candies[i-1] = max(candies[i-1],candies[i]+1);
        }
        int count=0;
        count = accumulate(candies.begin(),candies.end(),0);
        return count;
    }
};
