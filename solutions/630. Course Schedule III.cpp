class Solution {
public:
    int scheduleCourse1(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& left, vector<int>& right) { return left[1]<right[1];});
        priority_queue<int> pq;
        int day=0;
        int count=0;
        for(auto& c:courses) {
            if(day + c[0] <= c[1] ) { // course can be completed 
                pq.push(c[0]);
                day += c[0];
                ++count;
            }
            else if(pq.size() && (pq.top() > c[0]) ) { // improve the day
                day -= pq.top() - c[0];
                pq.pop();
                pq.push(c[0]);
            }   
        }
        return count;
    }
    // greedy, more clean
    int scheduleCourse2(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});
        priority_queue<int> pq;
        int now = 0;
        for(auto& c:courses) {
            pq.push(c[0]);
            now += c[0];
            if (now > c[1])
                now -= pq.top(), pq.pop();
        }
        return pq.size();
    }
    // very old solution self
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const std::vector<int>& a, const std::vector<int>& b) {
  return a[1] < b[1];
}); // ???? short by end time
        
        int len = courses.size();
        
        vector<vector<int>> dp(len,vector<int>(2,0)); // no of course complete, and minimum end date/ start for next work.
        vector<int> max_heap;
        
        
        for(int i=0;i<len;i++)
        {
            if(courses[i][1]>=courses[i][0])
            {
                if(i==0)
                {
                    dp[i][0] = 1; // one course can be completed
                    dp[i][1] = courses[i][0];
                    max_heap.push_back(courses[i][0]);
                }
                else
                {
                    if((dp[i-1][1] + courses[i][0]) <= courses[i][1]) // course can be completed
                    {
                        dp[i][0]= dp[i-1][0]+1;
                        dp[i][1]= dp[i-1][1] + courses[i][0];
                        max_heap.push_back(courses[i][0]);
                        push_heap(max_heap.begin(),max_heap.end());
                    }
                    else if(max_heap.front() > courses[i][0]) // improve finish time
                    {
                        dp[i][0]= dp[i-1][0]; // same
                        dp[i][1]= dp[i-1][1] + courses[i][0] - max_heap.front();
