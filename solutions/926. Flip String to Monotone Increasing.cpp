class Solution {
public:
    int minFlipsMonoIncr1(string s) {
        int n = s.size();
        vector<int> comm0(n+1,0);
        vector<int> comm1(n+1,0);
        
        if(s[0]=='0')
        {
            comm0[0]++;
        }
        else
            comm1[0]++;
        
        for(int i=1;i<n;++i)
        {
​
            comm0[i] = comm0[i-1];
            comm1[i] = comm1[i-1];
            if(s[i]=='0')
                comm0[i]++;
            else
                comm1[i]++;
        }
        int minF = n;
        minF = min(minF, comm0[n-1]);
        for(int i=1 ; i<n; ++i)
        {
            minF = min(minF, comm1[i-1] + comm0[n-1]- comm0[i-1]);
        }
        minF = min(minF, comm1[n-1]); 
        return minF;
    }
    int minFlipsMonoIncr2(string s) {
        int n = s.size();
        vector<int> comm1(n+1,0);
        
        if(s[0]=='1')
            comm1[0]++;
        
        for(int i=1;i<n;++i)
        {
            comm1[i] = comm1[i-1];
            if(s[i]=='1')
                comm1[i]++;
        }
        int minF = n;
        minF = min(minF, n - comm1[n-1]); // flip all zeros after
        for(int i=1 ; i<n; ++i)
        {
            minF = min(minF, comm1[i-1] +  ((n-i) - (comm1[n-1] - comm1[i-1])));
        }
        minF = min(minF, comm1[n-1]); // flip all ones before
        return minF;
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
            counter_flip = std::min(counter_one, counter_flip);
        }
        return counter_flip;
    }
};
