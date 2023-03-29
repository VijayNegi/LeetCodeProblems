class Solution {
public:
    // n2 sol
    int maxSatisfaction1(vector<int>& sat) {
        sort(begin(sat),end(sat));
        int result = 0,n=sat.size();
        for(int i=0;i<n;++i){
            int curr=0;
            for(int j=i;j<n;++j){
                curr += sat[j]*(j-i+1);
            }
            result = max(result,curr);
        }
        return result;
    }
    // nlog(n)
    int maxSatisfaction(vector<int>& sat) {
        sort(begin(sat),end(sat));
        int result = 0,n=sat.size();
        int pre=0;
        for(int i=n-1;i>=0;--i){
            if(i<n-1) sat[i] += sat[i+1];
            pre += sat[i];
            result = max(result,pre);
        }
        return result;
    }
};
