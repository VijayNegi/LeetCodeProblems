class Solution {
public:
    // 12 ms
    bool carPooling1(vector<vector<int>> trips, int capacity) {
        int n = trips.size();
        sort(begin(trips),end(trips), [](const vector<int>& a,const vector<int>& b) { if(a[1] < b[1]) return true; return false; } );  //using <= is throwing an exception for larger test cases
        
        auto cmp = [](pair<int,int>& left,pair<int,int>& right) { if(left.first > right.first) return true; return false; };
        priority_queue<pair<int,int>, std::vector<pair<int,int>>, decltype(cmp)> q(cmp);
        int curr_cap = capacity;
        
        for(auto& t: trips)
        {
            while(!q.empty())
            {
                auto& t1 =  q.top();
                if(t1.first <= t[1])
                {
                    curr_cap += t1.second;
                    q.pop();
                }
                else
                    break;
            }
            if(t[0] > curr_cap )
                return false;
            
            curr_cap -= t[0];
            q.push({t[2],t[0]});
            
        }
  
        return true;
    }
    // 8 ms
    bool carPooling(vector<vector<int>> trips, int capacity) {
        
        int stops[1001] = {0};
        
        for(auto& t:trips)
        {
            stops[t[1]] += t[0];
            stops[t[2]] -= t[0];
        }
        
        int pass = 0;
        for(int i=0;i<1001;++i)
        {
            pass += stops[i];
            if(pass > capacity)
                return false;
        }
        return true;
        
    }
    
};
