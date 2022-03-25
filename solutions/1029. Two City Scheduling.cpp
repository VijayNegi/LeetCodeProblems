class Solution {
public:
    int twoCitySchedCost1(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        int result=0;
        auto cmp = [](vector<int>& left,vector<int>& right){ return abs(left[0]-left[1]) > abs(right[0]-right[1]);};
        sort(begin(costs),end(costs),cmp);
        int c1=0,c2=0;
        for(auto p:costs)
        {
            if((p[0] < p[1]) && c1<n)
            {
                result += p[0];
                ++c1;
            }
            else if(c2 < n)
            {
                result += p[1];
                ++c2;
            }
            else
            {
                result += p[0];
                ++c1;
            }
        }
    
        return result;
    }
    // fly to one then get a refund
    int twoCitySchedCost2(vector<vector<int>>& costs) {
        vector<int> sol(costs.size());
        int sum=0;
        for(int i=0;i<costs.size();i++)
        {
            sum+=costs[i][0];
            sol[i]=(costs[i][0]-costs[i][1]);
        }
        sort(sol.begin(),sol.end(),greater());
        for(int i=0;i<((sol.size())/2);i++)
        {
            sum-=sol[i];
        }
        return sum;
    }
    // or sort with difference add from front and end
    int twoCitySchedCost(vector<vector<int>>& cs, int res = 0) {
      sort(begin(cs), end(cs), [](vector<int> &v1, vector<int> &v2) {
        return (v1[0] - v1[1] < v2[0] - v2[1]);
      });
      for (auto i = 0; i < cs.size() / 2; ++i) {
        res += cs[i][0] + cs[i + cs.size() / 2][1];
      }
      return res;
    }
};
