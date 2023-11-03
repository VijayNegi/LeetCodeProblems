class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> result;
        int k = target.size();
        int idx = 0;
        for(int i=1;i<=n && idx<k ;++i){
            if(i==target[idx]){
                result.push_back("Push");
                ++idx;
            }
            else{
                result.push_back("Push");
                result.push_back("Pop");
            }
        }
        return result;
    }
};
