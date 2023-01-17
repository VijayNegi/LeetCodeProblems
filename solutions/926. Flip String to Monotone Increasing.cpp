class Solution {
public:
    // self : 24ms
    int minFlipsMonoIncr1(string s) {
        int result=0,ones=0;
        for(auto& c:s)
            ones += c=='1';
        int n = s.size();
        result = min(n-ones,ones); // either flip all ones or all zeros
        int curr=0;
        for(int i=0;i<n-1;++i){
            curr += s[i]=='1';
            result = min(result,curr +  n-1-i-ones+curr);// from current centre - flip all ones before and flip all zeros after 
        }
        return result;
    }
    
    int minFlipsMonoIncr(string S ) 
        {
            int counter_one  = 0,counter_flip = 0;
            for (auto ch : S) {
            if (ch == '1') {
                ++counter_one;
            } else {
                ++counter_flip;
            }
            counter_flip = std::min(counter_one, counter_flip); // either we will have to flip all zeros before or all ones
        }
        return counter_flip;
    }
};
