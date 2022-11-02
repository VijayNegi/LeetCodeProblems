class Solution {
public:
    // self
    // or we could just diff each level string with all strings remaining in set 
    // but that would only work if bank has very less strings
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> s(bank.begin(),bank.end());
        if(s.count(end)==0)
            return -1;
        vector<string> level{start};
        string dict = "ACGT";
        int dist=0;
        while(level.size()){
            vector<string> next;
            for(auto g:level){
                for(int i=0;i<8;++i){
                    for(auto& d:dict){
                        if(g[i]!=d){
                            string temp = g;
                            temp[i]=d;
                            if(temp==end)
                                return dist+1;
                            if(s.count(temp)){
                                next.push_back(temp);
                                s.erase(temp);
                            }
                        }
                    }
                }
            }
            ++dist;
            level = next;
        }
        return -1;
    }
};
