class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> res(n,false);
        int m = *max_element(begin(candies),end(candies));
        for(int i=0;i<n;++i){
            if(candies[i]+extraCandies >= m)
                res[i]=true;
        }
        return res;
    }
};
