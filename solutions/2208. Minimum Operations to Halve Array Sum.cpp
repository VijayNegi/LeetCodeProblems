class Solution {
public:
    //contest 431ms
    int halveArray1(vector<int>& nums) {
        priority_queue<double> q;
        double sum=0;
        for(auto n:nums)
        {
            sum +=n;
            q.push(n);
        }
        
        double redsum=sum;
        int operations=0;
        while(redsum > sum/2)
        {
            double n = q.top();
            q.pop();
            redsum -= n/2;
            q.push(n/2);
            ++operations;
        }
        return operations;
    }
    // 319ms
    int halveArray(vector<int>& nums) {
        
        double sum = accumulate(begin(nums), end(nums), 0.0);
        priority_queue<double> pq(begin(nums), end(nums));
        
        double newSum=sum;
        int operations=0;
        while(newSum > sum/2)
        {
            double n = pq.top();
            pq.pop();
            newSum -= n/2;
            pq.push(n/2);
            ++operations;
        }
        return operations;
    }
};
