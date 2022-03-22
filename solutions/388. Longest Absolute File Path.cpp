class Solution {
public:
    int lengthLongestPath(string input) {
        stringstream ss(input);
        int longpath = 0;
        stack<int> stk;
        string s;
        while(!ss.eof())
        {
            getline(ss,s,'\n');
            int tabs=0;
            while(s[tabs]=='\t')
                ++tabs;
            s = s.substr(tabs);
            
            while(stk.size()> tabs)
                stk.pop();
            
            if(s.find('.')!= string::npos) //found a file
            {
                int path = stk.empty()? 0:stk.top() + stk.size();
                path += s.size();
                if(path>longpath)
                    longpath = path;
            }
            else // found a folder
            {
                int parent = stk.empty()?0:stk.top();
                stk.push(parent + s.size());
            }
        }
        
        return longpath;
    }
};
