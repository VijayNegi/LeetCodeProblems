class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int i=0,j=n-1;
        int score=0,result=0;
        while(i<=j) {
            if(power>= tokens[i]) {
                power -= tokens[i++];
                ++score;
                result = max(result,score);
            }
            else if(score>0) {
                power += tokens[j--];
                --score;
            }
            else break;
        }
        return result;
    }
};
