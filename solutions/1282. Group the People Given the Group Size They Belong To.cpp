class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> gId;
        int n = groupSizes.size();
        for(int i=0;i<n;++i){
            gId.push_back({groupSizes[i],i});
        }
        sort(gId.begin(),gId.end());
        vector<vector<int>> result;
        int i=0;
        while(i<n){
            int j = gId[i][0];
            vector<int> g;
            while(j){
                g.push_back(gId[i][1]);
                ++i,--j;
            }
            result.push_back(g);
        }
        return result;
    }
};
