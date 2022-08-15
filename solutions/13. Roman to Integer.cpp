class Solution {
public:
    int romanToInt(string s) {
        map<char,int> value;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        
        int n = s.size();
        char pre = 'M';
        int val=0;
        for(auto& c:s) {
            if(value[pre] < value[c])
                val -= 2*value[pre];
            pre = c;
            val += value[c];
        }
        return val;
    }
};
