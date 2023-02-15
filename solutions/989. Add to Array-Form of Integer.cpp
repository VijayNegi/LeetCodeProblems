class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(begin(num),end(num));
        int carry=0;
        for(auto& n:num){
            n += carry+ k%10;
            carry = n/10;
            n %= 10;
            k/=10;
            if(!carry && !k) break;
        }
        while(carry || k){
            int n = carry+ k%10;
            carry = n/10;
            n %= 10;
            k/=10;
            num.push_back(n);
        }
        reverse(begin(num),end(num));
        return num;
    }
};
