class Solution {
public:
    int minFlips1(int a, int b, int c) {
        int ab = a | b;
        int result=0;
        for(int i = 0; i<31;++i){
            int t1= c & 1<<i;
            if((ab & 1<<i) == t1)
                continue;
            if(t1)
                ++result;
            else{
                if((a & 1<<i) != t1)
                    ++result;
                if((b & 1<<i ) != t1)
                    ++result;
            }
        }
        return result;
    }
    int minFlips(int a, int b, int c) {
        int answer = 0;
        while (a != 0 | b != 0 | c != 0) {
            if ((c & 1) == 1) {
                if ((a & 1) == 0 && (b & 1) == 0) {
                    answer++;
                }
            } else {
                answer += (a & 1) + (b & 1);
            }
            
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return answer;
    }
};
