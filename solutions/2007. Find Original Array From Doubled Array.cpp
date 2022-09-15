class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n & 1) return {};
        vector<int> result;
        sort(begin(changed),end(changed));
        int l=0,r=1;
        while(l<n && r<n) {
            if(changed[l]==-1){
                ++l;
                if(l==r) ++r;
            }
            else if(2*changed[l] > changed[r] )
                ++r;
            else if(2*changed[l]==changed[r]) {
                result.push_back(changed[l++]);
                changed[r++] = -1;
            }
            else
                break;
        }
        if(result.size() != n/2)
           result.clear();
        return result;
    }
};
