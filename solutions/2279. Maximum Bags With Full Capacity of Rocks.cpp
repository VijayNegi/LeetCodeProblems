class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int addRocks) {
        int n = rocks.size();
        vector<int> bags(n,0);
        for(int i=0;i<n;++i){
            bags[i] = capacity[i]-rocks[i];
        }
        sort(bags.begin(),bags.end());
        int result=0;
        for(auto& k:bags){
            if(addRocks>=k){
                ++result;
                addRocks -=k;
            }
            else break;
        }
        return result;
    }
};
