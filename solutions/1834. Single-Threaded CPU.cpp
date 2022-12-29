        
        long t = 0;
        pq.push(tasks[0]);
        t = tasks[0][0];
        int i=1;
        vector<int> result;
        while(pq.size()){
            auto tsk = pq.top();
            pq.pop();
            t += tsk[1];
            result.push_back(tsk[2]);
            while(i<n && t >= tasks[i][0]){
                pq.push(tasks[i]);
                ++i;
            }
            if(pq.empty() && i<n){
                pq.push(tasks[i]);
                t = tasks[i][0];
                ++i;
            }
        }
        return result;
    }
    // older solution 841 ms
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
