class Solution {
public:
    // from : https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/discuss/743741/Detailed-General-Ideasolution-for-such-problems-(-AND-OR-GCD-)-in-O(N-*-log(-max(arri)-)-) 
    // 1416 ms
    int closestToTarget1(vector<int>& arr, int target) {
        set<int> s;
        int n = arr.size();
        int res=INT_MAX;
        for(int i=n-1;i>=0;--i){
            set<int> temp;
            temp.insert(arr[i]);
            res = min(res,abs(target-arr[i]));
            for(auto v: s) {
                int val = v & arr[i];
                res = min(res,abs(target-val));
                temp.insert(val);
            }
            s = temp;
        }
        return res;
    }
    // 213 ms
    int closestToTarget(vector<int>& arr, int target) {
        vector<int> q;
        q.reserve(32);
        int best = 1'000'000'000;
        for (size_t i = 0; i < arr.size(); i++) {
            for (auto& x : q) x &= arr[i];
            q.push_back(arr[i]);
            q.erase(unique(begin(q), end(q)), end(q));
            for (auto x : q) best = min(best, abs(target-x));
        }
        return best;
    }
};
