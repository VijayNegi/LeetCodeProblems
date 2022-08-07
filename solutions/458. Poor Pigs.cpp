class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int pigs = 0;
        int maxbuckets = 1;
        while (maxbuckets < buckets)
        {
            pigs += 1;
            maxbuckets*=minutesToTest / minutesToDie + 1;
        }
        return pigs;
    }
};
