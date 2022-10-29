class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<vector<int>> flowers;
        int n = plantTime.size();
        for(int i=0;i<n;++i){
            flowers.push_back({growTime[i],plantTime[i]});
        }
        sort(flowers.begin(),flowers.end(), greater<>());
        int result=0;
        int plantEnd=0;
        for(auto& f:flowers){
            plantEnd += f[1];
            result = max(result, plantEnd+ f[0]);
        }
        return result;
    }
};
