class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        auto cmp = [&](vector<int>& l,vector<int>& r){
            if(l[1]==r[1]) return l[0]>r[0];
            return l[1]>r[1];
        };
        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
        int l=0,r=n-1;
        while(l<candidates && l<n){
            pq.push({l,costs[l]});
            ++l;
        }
        while(r>n-candidates-1 && r>=0 && r>=l){
            pq.push({r,costs[r]});
            --r;
        }
        long long cost=0;
        while(k--)
        {
            auto t = pq.top();
            pq.pop();
            cost += t[1];
            if(l<=r){
                if(t[0]<l){
                     pq.push({l,costs[l]});
                    ++l;
                }
                else{
                    pq.push({r,costs[r]});
                    --r;
                }
            }
        }
        return cost;
        
    }
};
