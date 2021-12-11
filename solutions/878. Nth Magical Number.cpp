        int period = (lcm/a) + (lcm/b) - 1;
        //cout<<"period="<<period<<"\n";
        int m = n/period;
        int r = (n%period);
        //cout<<"m="<<m<<"\n";
        //cout<<"r="<<r<<"\n";
        vector<int> first{0};//(period+1,0);
        
        for(int i = 1; i<=lcm/a;i++)
        {
            first.push_back(a*i);
        }
        for(int i = 1; i<=lcm/b;i++)
        {
            first.push_back(b*i);
        }
        sort(begin(first),end(first));
        
        return ((ll)m*lcm + first[r])%mod;
        
            
    }
    // binary search, 0 ms
    int nthMagicalNumber(int n, int a, int b) {
        
        int g = gcd(a,b);
        //cout<<"g="<<g<<"\n";
        int lower = min(a,b);
        if(g==lower)
            return ((ll)lower*n)%mod;
        int lcm = (a*b)/g;
        //cout<<"lcm="<<lcm<<"\n";
        int period = (lcm/a) + (lcm/b) - 1;
        //cout<<"period="<<period<<"\n";
        int m = n/period;
        int r = (n%period);
        //cout<<"m="<<m<<"\n";
        //cout<<"r="<<r<<"\n";
        //vector<int> first{0};//(period+1,0);
        
        int l = 0;
        int h = lcm;
        
        while(l<h)
        {
            int mid = l +(h-l)/2;
            if(mid/a + mid/b - mid/lcm <r)
                l = mid +1;
            else
                h = mid;
        }
        
        return ((ll)m*lcm + h)%mod;
        
            
    }
};
