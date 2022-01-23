class Solution {
public:
    vector<int> sequentialDigits1(int low, int high) {
        int n,dl,dh;
        dl= dh = 0;
        n=low;
        while(n)
        {
            ++dl;
            n/=10;
        }
        n=high;
        while(n)
        {
            ++dh;
            n/=10;
        }
        vector<int> res;
        for(int i=dl;i<=dh;++i)
        {
            for(int j=1;j<=10-i;++j)
            {
                int num=0;
                for(int k=j;k<j+i;++k)
                    num = num*10 + k;
                if(num<low)
                    continue;
                if(num>high)
                    break;
                res.push_back(num);
            }
        }
        return res;
    }
    // generate next numbers on each step
    vector<int> sequentialDigits2(int l, int h) {                
        queue<int> q{{1,2,3,4,5,6,7,8,9}}; //9 can be removed
        vector<int> ans;
        while(!q.empty()) {
            int cur = q.front();    q.pop();
            if(cur > h) break; // reach upperbound. Done
            if(cur >= l && cur <= h) ans.push_back(cur);
            int num = cur % 10; // Ready for hoisting operation           
            int next = cur * 10 + (num + 1);
            if(num < 9) q.push(next);// 1234->12345
        }
        return ans;
    }
    //sliding window
    vector<int> sequentialDigits(int low, int high) {                
        string s = "123456789";
        vector<int> ans;
        for(int i=1;i<=9;++i)
        {
            for(int j=1;j<=10-i;++j)
            {
                int num = stoi(s.substr(j-1,i));
                if(num<low)
                    continue;
                if(num>high)
                    break;
                ans.push_back(num);
            }
        }
        return ans;
    }
    
};
