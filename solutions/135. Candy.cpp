class Solution {
public:
    // self : 47ms
    int candy1(vector<int>& ratings) {
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
    // old : 26ms
    int candy(vector<int>& ratings) {
        int result = 1;
        int start = 0;
        int n = ratings.size();
        bool up = true;
        int peak = 0;
        int count=1;
        for(int i=1;i<n;++i)
        {
            if(ratings[i]>ratings[i-1])
            {
                if(!up) {
                    result -= min(peak,count) -1 ;
                    count=1;
                    up = true;
                    peak = 0;
                }
                ++count;
                result +=count;
            }
            else if(ratings[i]<ratings[i-1]) {
                if(up) {
                    peak = count;
                    count = 1;
                    up = false;
                }
                ++count;
                result +=count;
            }
            else
            {
                if(!up)
                    result -= min(peak,count) -1;
        
                count =1;
                result +=count;
                up = true;
                peak = 0;
            }
        }
        if(!up)
            result -= min(peak,count) -1;
​
        return result;
    }
​
};
