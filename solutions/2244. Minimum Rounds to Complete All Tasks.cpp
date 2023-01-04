class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> count;
        for(auto& t:tasks)
            count[t]++;
        int result=0;
        for(auto& t:count){
            if(t.second ==1)
                return -1;
            result += t.second/3;
            if(t.second%3)
                ++result;
        }
        return result;
    }
};
