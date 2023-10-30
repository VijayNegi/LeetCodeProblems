class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int,int> bits;
        function<int(int)> getBits = [](int n){
            int count = 0;
            while(n){
                n = n & (n-1);
                ++count;
            }
            return count;
        };
        for(auto& n:arr){
            bits[n] = getBits(n);
        }
        sort(begin(arr),end(arr),[&](int& l,int& r){
            if(bits[l] == bits[r]) return l<r;
            return bits[l] < bits[r];
        });
        return arr;
    }
};
