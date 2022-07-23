const int range = 2e4+1;
const int offset = 1e4;
struct stree {
    int tree[range*2];
    stree(){
        fill(tree,tree+2*range,0);
    }
    void update(int val){
        val += range;
        tree[val]++;
        while(val != 0){
            val >>=1;
            tree[val]++;
        }
    }
    int count(int val) {
        int l = range;
        int r = val+range;
        int sum=0;
        while(l<=r) {
            if((l%2) == 1) {
                sum += tree[l];
                l++;
            }
            if( (r%2) == 0) {
                sum += tree[r];
                r--;
            }
            l >>= 1;
            r >>= 1;
        }
        return sum;
        
    }
};
class Solution {
    
public:
    // TLE: 50/65 test cases. binary search
    // distance has linear time complaxicity
    vector<int> countSmaller1(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,0);
        multiset<int> s;
        s.insert(nums.back());
        for(int i=n-2;i>=0;--i) {
            auto it = s.lower_bound(nums[i]);
            result[i] = distance(s.begin(),it);
            s.insert(nums[i]);
        }
        return result;
    }
    // segment tree: 284 ms
    vector<int> countSmaller2(vector<int>& nums) {
        stree st;
        int n = nums.size();
