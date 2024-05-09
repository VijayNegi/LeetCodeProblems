class Solution {
public:
    long long maximumHappinessSum(vector<int>& hp, int k) {
        sort(begin(hp),end(hp),greater<>());
        long res=0;
        int sub=0;
        for(int i=0;i<k;++i){
            res += max(0,hp[i]-sub);
            ++sub;
            if(hp[i]<=sub)
                break;
        }
        return res;
    }
};
