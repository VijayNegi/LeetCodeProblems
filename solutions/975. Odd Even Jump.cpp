class Solution {
public:
    int oddEvenJumps1(vector<int>& arr) {
        set<int> s;
        map<int,int> val2idx;
        int n = arr.size(),result=0;
        vector<vector<int>> reach(n,vector<int>(2,0));
        reach[n-1][0] = reach[n-1][1] = 1;
        ++result;
        s.insert(arr[n-1]);
        val2idx[arr[n-1]] = n-1;
        for(int i=n-2;i>=0;--i){
            auto it = s.lower_bound(arr[i]);
            if(it != s.end()){
                reach[i][1] = reach[val2idx[*it]][0];
                if(*it == arr[i])
                    reach[i][0] = reach[val2idx[*it]][1];
                else if(it != s.begin()){
                    auto p = prev(it);
                    reach[i][0] = reach[val2idx[*p]][1];
                } 
            }
            else {
                 auto p = prev(it);
                reach[i][0] = reach[val2idx[*p]][1];
            }
            if( reach[i][1] ) //reach[i][0] ||
                ++result;
            val2idx[arr[i]] = i;
            s.insert(arr[i]);
        }
        return result;
    }
    // https://leetcode.com/problems/odd-even-jump/discuss/217981/JavaC%2B%2BPython-DP-using-Map-or-Stack
    // same and concise
    int oddEvenJumps(vector<int>& A) {
        int n  = A.size(), res = 1;
        vector<int> higher(n), lower(n);
        higher[n - 1] = lower[n - 1] = 1;
        map<int, int> map;
        map[A[n - 1]] = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            auto hi = map.lower_bound(A[i]), lo = map.upper_bound(A[i]);
            if (hi != map.end()) higher[i] = lower[hi->second];
            if (lo != map.begin()) lower[i] = higher[(--lo)->second];
            if (higher[i]) res++;
            map[A[i]] = i;
        }
        return res;
    }
};
