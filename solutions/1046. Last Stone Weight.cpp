class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(begin(stones),end(stones));
        while(pq.size()>1)
        {
            int s1 = pq.top(); pq.pop();
            int s2 = pq.top(); pq.pop();
            if(s1>s2)
                pq.push(s1-s2);    
        }
        return pq.size()? pq.top():0;
    }
};
