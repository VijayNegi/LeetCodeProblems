class Solution {
public:
    int compareVersion1(string version1, string version2) {
        std::istringstream ss1(version1), ss2(version2);
        int ans = 0;
        string s1,s2;
        while(true)
        {
            s1.clear(),s2.clear();
            int n1 = 0,n2=0;
            if(getline(ss1,s1,'.'))
               n1 = stoi(s1);
            if(getline(ss2,s2,'.'))
                n2 = stoi(s2);
           
            if(s1.empty() && s2.empty())
                return 0;
            if(n1!=n2)
               return n1>n2?1:-1;
        }
        return 0;
    }
    int compareVersion(string version1, string version2) {
        for(auto& w : version1) if (w == '.') w=' ';
        for(auto& w : version2) if (w == '.') w=' ';
        istringstream s1(version1), s2(version2);
        while(1) {
            int n1,n2;
            if (not(s1 >> n1) ) n1 = 0;
            if (not(s2 >> n2) ) n2 = 0;
            if (not s1 and not s2) return 0;
            if (n1<n2) return -1;
            if (n1>n2) return 1;
        }
    }
};
