using pi = pair<int,int>;
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
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
};
