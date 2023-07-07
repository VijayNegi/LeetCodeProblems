class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int start=0;
        int n = answerKey.size();
        int fill=0;
        int result=0;
        for(int i=0;i<n;++i){
            if(answerKey[i]=='F')
                ++fill;
            while(fill>k){
                if(answerKey[start] == 'F')
                    --fill;
                ++start;
            }
            result = max(result,i-start+1);
        }
        start = fill = 0;
        for(int i=0;i<n;++i){
            if(answerKey[i]=='T')
                ++fill;
            while(fill>k){
                if(answerKey[start] == 'T')
                    --fill;
                ++start;
            }
            result = max(result,i-start+1);
        }
        return result;
    }
};
