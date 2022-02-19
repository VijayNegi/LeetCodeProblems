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
