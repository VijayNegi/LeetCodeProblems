class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>& left, vector<int>& right) { return left[1]<right[1];});
        priority_queue<int> pq;
        int day=0;
        int count=0;
        for(auto c:courses) {
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
};
