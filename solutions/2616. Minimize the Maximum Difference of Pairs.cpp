class Solution {
public:
    // Note- min dif pairs will always be consicutive 
    // fails on below bacause we need to select 3 not 2.
    // [3,4,2,3,2,1,2]
    // 3
    // similar solution check later
    // https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/discuss/3885909/Fastest-Python-576ms-100-oror-Non-Binary-Search-oror-Plz-Upvote
    int minimizeMax1(vector<int>& nums, int p) {
        if(nums.size()==1 || p==0) return 0;
        sort(begin(nums),end(nums));
        vector<pair<int,int>> diffPos;
        for(int i=1;i<nums.size();++i)
        {
            diffPos.push_back({abs(nums[i]-nums[i-1]),i-1});
        }
        sort(begin(diffPos),end(diffPos));
        unordered_set<int> used;
        int result=0;
        for(int i=0;i<diffPos.size();++i){
            int idx = diffPos[i].second;
            if(used.count(idx-1) || used.count(idx+1))
                continue;
            result = max(result,diffPos[i].first);
            used.insert(idx);
            if(used.size()>=p)
                break;
        }
        //cout<<used.size();
        return result;
    }
    // binary search based on diff
    // https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/discuss/3395750/JavaC%2B%2BPython-Binary-Search
    int minimizeMax(vector<int>& A, int p) {
        sort(A.begin(), A.end());
        int n = A.size(), left = 0, right = A[n - 1] - A[0];
        while (left < right) {
            int mid = (left + right) / 2, k = 0;
            for (int i = 1; i < n && k < p; ++i) {
                if (A[i] - A[i - 1] <= mid) {
                    k++;
                    i++;
                }
            }
            if (k >= p)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
