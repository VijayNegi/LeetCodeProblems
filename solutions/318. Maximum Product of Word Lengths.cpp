class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> hash(n,0);
        int i=0;
        for(auto& s:words) {
            for(auto& c:s )
                hash[i] |= 1<<(c-'a');
            ++i;
        }
        int result=0;
        for(int i=0;i<n-1;++i) 
            for(int j=i+1;j<n;++j) {
                if((hash[i] & hash[j]) == 0)
                    result = max(result, (int)(words[i].size()*words[j].size()));
            }
        return result;
    }
};
