class Solution {
public:
    int maxConsecutiveAnswers1(string answerKey, int k) {
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
    // single loop
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxSize = 0;
        unordered_map<char, int> count;
        
        for (int right = 0; right < answerKey.length(); right++) {
            count[answerKey[right]]++;
            int minor = min(count['T'], count['F']);
            
            if (minor <= k) {
                maxSize++;
            } else {
                count[answerKey[right - maxSize]]--;
            }
        }
​
        return maxSize;
    }
};
