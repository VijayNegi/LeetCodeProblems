class Solution {
public:
    // STL
    int minAreaRect1(vector<vector<int>>& points, int res = INT_MAX) {
      unordered_map<int, set<int>> x;
      for (auto p : points) x[p[0]].insert(p[1]);
      for (auto i = x.begin(); i != x.end(); ++i)
        for (auto j = next(i); j != x.end(); ++j) {
          if (i->second.size() < 2 || j->second.size() < 2) continue;
          vector<int> y;
          set_intersection(begin(i->second), end(i->second),
            begin(j->second), end(j->second), back_inserter(y));
          for (int k = 1; k < y.size(); ++k)
            res = min(res, abs(j->first - i->first) * (y[k] - y[k - 1]));
        }
      return res == INT_MAX ? 0 : res;
    }
    // another solution
    int minAreaRect(vector<vector<int>>& points) {
        int MinArea = INT_MAX;
        unordered_map<int, unordered_set<int> > mapX;
        for(const auto& a: points)
            mapX[a[0]].insert(a[1]);
        
        for(int i=0;i<points.size()-1;i++) {
             if(mapX[points[i][0]].size()<2)
                 continue;
            for(int j=i+1;j<points.size();j++){   
                if( points[i][0] == points[j][0] || points[i][1] == points[j][1])
                    continue;
                if((abs(points[i][0] - points[j][0]) * abs( points[i][1] - points[j][1])) >= MinArea)
                   continue;
             
                if(mapX[ points[j][0] ].size()<2) 
                    continue;
                if(mapX[ points[i][0] ].count( points[j][1] ) && mapX[ points[j][0] ].count( points[i][1] ))
                    MinArea = min( abs(points[i][0] - points[j][0]) * abs( points[i][1] - points[j][1] ),MinArea);
            }
        }
        if(MinArea==INT_MAX) return 0;
        return MinArea;
    }
};
