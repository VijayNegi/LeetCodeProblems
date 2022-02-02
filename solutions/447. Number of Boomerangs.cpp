class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        int result=0;
        for(int i=0;i<n;++i)
        {
            unordered_map<int,long> distance;
            for(int j=0;j<n;++j)
            {
                if(i==j)
                    continue;
                long dx = points[i][0]-points[j][0];
                long dy = points[i][1]-points[j][1];
                long dist = dx*dx + dy*dy;
                
                result += distance[dist]*2;
                ++distance[dist];
            }
        }
        return result;     
    }
};
