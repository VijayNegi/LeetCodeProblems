class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time2reach;
        int n = dist.size();
        for(int i=0;i<n;++i)
            time2reach.push_back((dist[i]+speed[i]-1)/speed[i]);
        sort(begin(time2reach),end(time2reach));
        int result=0;
        while(result<n){
            if(time2reach[result] <= result)
                break;
            ++result;
        }
        return result;
    }
};
