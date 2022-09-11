const int mod = 1e9+7;
class Solution {
public:
​
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
     
        vector<pair<int,int>> eng;
        for(int i=0;i<n;i++)
        {
            eng.push_back({efficiency[i],speed[i]});
        }
        sort(eng.begin(),eng.end(),greater<>());
        long result = 0;
        long sum = 0;
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto&[e,s]:eng)
        {
            pq.push(s);
            sum+=s;
            if(pq.size()>k) {
                sum-=pq.top();
                pq.pop();
            }
            result = max(result, sum * e);
        }
        
        return result % static_cast<int>(1e9+7);
    }
};
