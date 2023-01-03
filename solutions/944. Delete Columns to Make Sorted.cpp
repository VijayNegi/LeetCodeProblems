class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int result=0;
        int n = strs.size();
        int l = strs[0].size();
        for(int i=0;i<l;++i){
            for(int j=1;j<n;++j){
                if(strs[j][i]<strs[j-1][i]){
                    ++result;
                    break;
                }
            }
        }
        return result;
    }
};
