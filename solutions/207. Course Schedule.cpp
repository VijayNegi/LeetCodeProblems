class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prereq) {
​
        vector<vector<int>> dep(n);
        vector<int> inbound(n,0);
        for(auto& p:prereq)
        {
            dep[p[1]].push_back(p[0]);
            inbound[p[0]]++;
        }
        list<int> course;
        for(int i=0;i<n;++i)
            if(inbound[i]==0)
                course.push_back(i);
        int done = course.size();
        while(!course.empty())
        {
            int c = course.front();
            course.pop_front();
            for(auto d:dep[c])
            {
                --inbound[d];
                if(inbound[d]==0)
                {
                    course.push_back(d);
                    ++done;
                }
            }
        }
        
        return done == n;
    }
};
