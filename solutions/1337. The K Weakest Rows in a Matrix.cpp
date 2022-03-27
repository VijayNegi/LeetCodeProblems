using pi = pair<int,int>;
class Solution {
public:
    vector<int> kWeakestRows1(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        auto cmp = [](pi& left, pi& right){ if(left.first == right.first) 
                                            return left.second >right.second; 
                                          return left.first > right.first;   };
        priority_queue<pi,vector<pi>,decltype(cmp)> q(cmp);
        
        for(int i=0;i<rows;++i)
        {
            int sum = 0;
            sum = accumulate(begin(mat[i]),end(mat[i]),sum);
            q.push({sum,i});
        }
        vector<int> result;
        while(k--)
        {
            auto t = q.top();
            q.pop();
            result.push_back(t.second);
        }
        return result;
    }
    
    // **************
    // use binary search for each row as solders are sorted
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
      set<pair<int, int>> strength_index; // pairs of (strength, row index)
      for (int i = 0; i < mat.size(); ++i) { // O(M)
        strength_index.emplace(getStrength(mat[i]), i); // O(logN + logK) = O(log(NK))
        if (strength_index.size() > k) // remove last item if exceeding size k
          strength_index.erase(--strength_index.end());  
      }  
      
      // form result array
      vector<int> res;
      for (auto& p : strength_index)
        res.push_back(p.second);
      return res;
    }
    
    // get strength of a row: time complexity O(logN)
    int getStrength(vector<int> & row) {
      // find position of first 0 by binary search  
      auto first0 = lower_bound(row.begin(), row.end(), 0, greater<int>());
      return first0 - row.begin();  
    }
};
