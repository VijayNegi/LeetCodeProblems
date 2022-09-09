class Solution {
public:
    // self 1807 ms
    int numberOfWeakCharacters1(vector<vector<int>>& prop) {
        map<int,multiset<int>> pmap;
        for(auto& c:prop){
            pmap[c[0]].insert(c[1]);
        }
        int groups = pmap.size();
        vector<int> commu(groups,0);
        auto it = pmap.rbegin();
        int n = groups-1;
        while(it != pmap.rend()) {
            if(n<(groups-1))
                commu[n] = commu[n+1];
            commu[n--] = max(commu[n],*max_element(begin(it->second),end(it->second)));
            ++it;
        }
        int result=0;
        n=0;
        for(auto& g:pmap){
            if(n==(groups-1))
                break;
            
            for(auto& k:g.second) {
                if(k<commu[n+1])
                    ++result;
            }
            ++n;
        }
        return result;
    }
    // 700 ms
     int numberOfWeakCharacters(vector<vector<int>> &properties)
     {
          auto comp = [](vector<int> &a, vector<int> &b){
              if (a[0] == b[0])   // Note : reverse sorting in same group
                   return a[1] > b[1];
                return a[0] < b[0];
          };
          sort(properties.begin(), properties.end(), comp); //sorting the array
          int mtn = INT_MIN;                                //max till now while moving from right
          int ans = 0;
​
          for (int i = properties.size() - 1; i >= 0; i--) {
               if (properties[i][1] < mtn) // if the second parameter is also less increase the ans
                    ans++;
               mtn = max(mtn, properties[i][1]);
          }
          return ans;
     }
};
​
