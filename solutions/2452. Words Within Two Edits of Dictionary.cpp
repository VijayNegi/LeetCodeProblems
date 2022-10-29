// Try Trie solution
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for(auto& q:queries){
            bool f=false;
            for(auto& d:dictionary){
                int diff=0;
                for(int i=0;i<d.size();++i){
                    diff += q[i]!=d[i];
                }
                if(diff<3){
                    f=true;
                    break;
                }
            }
            if(f)
                result.push_back(q);
        }
        return result;
    }
};
