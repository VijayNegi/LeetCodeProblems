class Solution {
public:
    // self, contest
    int splitNum1(int num) {
        vector<int> count(10,0);
        string str= to_string(num);
        int n = str.size();
        for(auto& c:str)
            count[c-'0']++;
        int i=9;
        int result=0;
        int multiple = 1;
        int flag = false;
        while(i>0){
            if(!count[i]){
                --i;
                continue;
            }
            count[i]--;
            result += i*multiple;
            
            if(!flag)
                flag = true;
            else{
                multiple *= 10;
                flag = false;
            }
        }
        return result;
    }
    int splitNum2(int num) 
    {
        string a,b,s=to_string(num);
        sort(s.begin(),s.end());
        for(int i=0;i<s.size();i++) i&1? b.push_back(s[i]):a.push_back(s[i]);
        return stoll(a)+stoll(b);
    }
    int splitNum(int num) {
        vector<int> v;
        while(num > 0){
            v.push_back(num%10);
            num = num/10;
        }
        sort(v.begin(), v.end());
        int n1 = 0, n2 = 0;
        for(int i = 0; i < v.size(); i = i+2){ n1 = n1*10 + v[i]; }
        for(int i = 1; i < v.size(); i = i+2){ n2 = n2*10 + v[i]; }
        return n1 + n2;
    }
};
