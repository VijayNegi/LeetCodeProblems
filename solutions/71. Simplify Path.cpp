class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> res;
        string line;
        while(getline(ss,line,'/'))
        {
            if(line == "" || line == ".")
                continue;
            else if(line == "..")
            {
                if(res.size())
                    res.pop_back();
            }
            else
                res.push_back(line);
        }
        string simpath;
        for(auto dir:res)
            simpath += "/"+ dir;
        if(simpath.empty())
            return "/";
        return simpath;
    }
};
