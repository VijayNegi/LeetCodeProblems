class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        auto cmp = [&](int left,int right) { return (tasks[left][0] > tasks[right][0]);};
        auto cmp1 = [&](int left,int right) { if(tasks[left][1] == tasks[right][1]) return left > right; return tasks[left][1] > tasks[right][1]; };
        priority_queue<int,vector<int>,decltype(cmp)> enque(cmp);
        priority_queue<int,vector<int>,decltype(cmp1)> process(cmp1);
        
        for(int i=0;i<tasks.size();++i)
            enque.push(i);
        vector<int> result;
        long time = 0;
        while(!enque.empty() || !process.empty())
        {
            // pop all jobs less then or equal then time from enque
            while(!enque.empty() && tasks[enque.top()][0] <= time)
            {
                process.push(enque.top());
                enque.pop();
            }
            
            if(process.empty()) // not rechable if both are empty
            {
                time = tasks[enque.top()][0];
               
                while(!enque.empty() && tasks[enque.top()][0] <= time)
                {
                    process.push(enque.top());
                    enque.pop();
                }
            }
            
            result.push_back(process.top());
            time += tasks[process.top()][1];
            process.pop();
            
        }
        
        return result;
    }
};
