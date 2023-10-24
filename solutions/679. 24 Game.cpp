class Solution {
public:
    double elipson = pow(10.0, -5);
    vector<char> operations = {'+','-','*','/'};
        // https://leetcode.com/problems/24-game/discuss/107685/679.-24-Game-C%2B%2B-Recursive
    bool judgePoint241(vector<int>& nums) {
        vector<double> vec;
        for(auto n : nums){
            vec.push_back(n*1.0);
        }
        return find24(vec);
    }
​
    bool find24(vector<double> vec){
        if(vec.size() == 1){
            return abs(vec[0] - 24.0) <= elipson;
        }
        for(int i = 0; i < vec.size(); ++i){//each time we pick up two number for computation
            for(int j = 0; j < vec.size(); ++j){
                if(i == j) continue;
                vector<double> res;
                for(int k = 0; k < vec.size(); ++k){
                    if(k != i && k != j) res.push_back(vec[k]);
                }
                for(auto op : operations){
                    if((op == '+' || op == '*') && i > j) continue;//no need to re-calculate
                    if(op =='/'  && vec[j] == 0.0) continue;
                    switch(op){
                        case '+': res.push_back(vec[i] + vec[j]); break;
                        case '-': res.push_back(vec[i] - vec[j]); break;
                        case '*': res.push_back(vec[i] * vec[j]); break;
                        case '/': res.push_back(vec[i] / vec[j]); break;
                    }
                    if(find24(res)) return true;
                    res.pop_back();//!!!important
                }
            }
        }
        return false;
    }
    // https://leetcode.com/problems/24-game/discuss/401033/C%2B%2B-Concise-code-with-only-one-helper-function
    vector<double> combine2(double a, double b) {
        return {a / b, b / a, a + b, a - b, b - a, a * b};
    }
    static constexpr double eps = 1e-4;
    bool judgePoint24(vector<int>& nums) {
        vector<int> id ({0, 1, 2, 3});
        do {
            int a = nums[id[0]], b = nums[id[1]], c = nums[id[2]], d = nums[id[3]];
            for (auto x: combine2(a, b))
                for (auto y: combine2(c, d))
                    for (auto z: combine2(x, y)) 
                        if (abs(z - 24) < eps) return true;
            for (auto x: combine2(a, b))
                for (auto y: combine2(c, x))
                    for (auto z: combine2(d, y))
                        if (abs(z - 24) < eps) return true;
        } while (next_permutation(id.begin(), id.end()));
        return false;
    }
};
