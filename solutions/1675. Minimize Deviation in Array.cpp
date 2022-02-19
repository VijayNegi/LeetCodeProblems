//https://leetcode.com/problems/minimize-deviation-in-array/discuss/955262/C%2B%2B-intuitions-and-flip
//https://leetcode.com/problems/minimize-deviation-in-array/discuss/952857/JavaC%2B%2BPython-Priority-Queue
//https://leetcode.com/problems/minimize-deviation-in-array/discuss/1042240/C%2B%2B-Explanation-%2B-Intuitive-priority-queue-solution
class Solution {
public:
    // TLE
    int minimumDeviation1(vector<int>& nums) {
        //priority_queue<int> max;
        //priority_queue<int,vector<int>,greater<int>> min;
        
        set<int> numset;
        for(auto& n:nums)
        {
            numset.insert(n);
        }
        int minDev = *numset.rbegin() - *numset.begin();
        bool update = true;
        while(update)
        {
            int low = *numset.begin();
            int high = *numset.rbegin();
            update = false;
            //cout<<"h-l = "<<high<<"-"<<low<<" dev="<<minDev<<endl;
            if(high%2==0) //high should be even 
            {
                if(abs(high/2 - low) < minDev)
                {
                    //cout<<"high/2"<<endl;
                    numset.erase(high);
                    //max.pop();
                    numset.insert(high/2);
                    high = *numset.rbegin();
                    low = *numset.begin();
                    //low = min
                    minDev = high - low;
                    update = true;
                }
            }
            //cout<<"h-l = "<<high<<"-"<<low<<" dev="<<minDev<<endl;
            if(low%2==1) // low should be odd
            {
                if(abs(high - low*2) < minDev)
                {
                    //cout<<"low*2"<<endl;
                    numset.erase(low);
                    //min.pop();
                    numset.insert(low*2);
                    high = *numset.rbegin();
                    low = *numset.begin();
                    
                    minDev = high - low;
                    update = true;
                }
            }
             //cout<<"h-l = "<<high<<"-"<<low<<" dev="<<minDev<<endl;
        }
        return minDev;
    }
    int minimumDeviation2(vector<int>& nums) {
        int res = INT_MAX, min_n = INT_MAX;
        priority_queue<int> pq;
        for (auto n : nums) {
            n = n % 2 ? n * 2 : n;
            pq.push(n);
            min_n = min(min_n, n); 
        }
        while (pq.top() % 2 == 0) {
            res = min(res, pq.top() - min_n);
            min_n = min(min_n, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        return min(res, pq.top() - min_n);
    }
    int minimumDeviation(vector<int>& A) {
        set<int> s;
        for (int &a : A)
            s.insert(a % 2 ? a * 2 : a);
        int res = *s.rbegin() - *s.begin();
        while (*s.rbegin() % 2 == 0) {
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            res = min(res, *s.rbegin() - *s.begin());
        }
        return res;
    }
};
