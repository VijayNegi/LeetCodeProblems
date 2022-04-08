// Great explanation
// https://leetcode.com/problems/task-scheduler/discuss/104500/Java-O(n)-time-O(1)-space-1-pass-no-sorting-solution-with-detailed-explanation
class Solution {
public:
    // 90 ms
    // https://leetcode.com/problems/task-scheduler/discuss/104504/C%2B%2B-8lines-O(n)
    int leastInterval1(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int mx = 0;
        for(auto& c: tasks)
        {
            m[c]++;
            mx = max(mx,m[c]);
        }
        int result = (mx-1)*(n+1);
        for(auto it:m)
            if(it.second == mx) ++result;
        return max(result,(int)tasks.size());
    }
    
    // 104 ms
    // emulate 
    //https://leetcode.com/problems/task-scheduler/discuss/104493/C%2B%2B-Java-Clean-Code-Priority-Queue
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<int> pq;
        for (pair<char, int> count : counts) {
            pq.push(count.second);
        }
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<int> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (int cnt : tmp) {
                if (--cnt) {
                    pq.push(cnt);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};
