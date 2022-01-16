class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int pre = -1;
        int maxd = 0;
        
        for(int i=0;i<n;++i)
        {
            if(seats[i])
            {
                int dist = pre<0 ? i:(i - pre)/2;
                maxd = max(maxd,dist);
                pre = i;
            }
        }
        maxd = max(maxd,n-pre-1);
        
        return maxd;
    }
};
