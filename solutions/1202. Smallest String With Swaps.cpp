    {
        iota(begin(parent),end(parent),0);
    }
    int find(int idx)
    {
        if(idx == parent[idx])
            return idx;
        return parent[idx] = find(parent[idx]);
    }
    
    void merge(int idx1, int idx2)
    {
        int pidx1 = find(idx1);
        int pidx2 = find(idx2);
        
        if(pidx1 == pidx2)
            return;
        parent[pidx2] = pidx1;
    }
};
​
class Solution {
public:
    // my solution: 263ms
    string smallestStringWithSwaps1(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        DSU dset(n);
        for(auto v:pairs)
            dset.merge(v[0],v[1]);
        unordered_map<int,multiset<char>> gmap;
        for(int i=0;i<n;++i)
        {
            gmap[dset.find(i)].insert(s[i]);
        }
        string result;
        
        for(int i=0;i<n;++i)
        {
            auto it = gmap[dset.find(i)].begin();
            result += *it;
            gmap[dset.find(i)].erase(it);
        }
        return result;
    }
    
    int find(vector<int>& ds, int i) {
      return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    // avoiding multiset: 189ms
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
      vector<int> ds(s.size(), -1);
      vector<vector<int>> m(s.size());
      for (auto& p : pairs) {
        auto i = find(ds, p[0]), j = find(ds, p[1]);
        if (i != j) 
            ds[j] = i;
      }
      for (auto i = 0; i < s.size(); ++i) 
          m[find(ds, i)].push_back(i);
      for (auto &ids : m) {
        string ss = "";
        for (auto id : ids) 
            ss += s[id];
        sort(begin(ss), end(ss));
        for (auto i = 0; i < ids.size(); ++i) 
            s[ids[i]] = ss[i];
      }
      return s;
    }
};
