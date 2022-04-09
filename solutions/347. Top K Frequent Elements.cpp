class Solution {
public:
    // nlogn
    vector<int> topKFrequent1(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        
        for(auto& n:nums)
            count[n]++;
        function<bool(int,int)> cmp = [&](int a,int b){ if(count[a]<count[b])
                                                  return true;
                                                 return false; };
        priority_queue<int,vector<int>, decltype(cmp)> q(cmp);
        
        for(auto& [n,c]:count)
        {
            q.push(n);
        }
        
        vector<int> result;
        while(k--)
        {
            result.push_back(q.top());
            q.pop();
        }
        
        return result;
        
    }
    // nlogk: 16ms
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto& n:nums)
            count[n]++;
        function<bool(int,int)> cmp = [&](int a,int b){ if(count[a]>count[b])
                                                  return true;
                                                 return false; };
        priority_queue<int,vector<int>, decltype(cmp)> q(cmp);
        
        for(auto& [n,c]:count)
        {
            q.push(n);
            if(q.size()>k)
                q.pop();
        }
        
        vector<int> result;
        while(!q.empty())
        {
            result.push_back(q.top());
            q.pop();
        }
        
        return result;
    }
    // O(n) : 12 ms , note : other solution is quickselect which is also O(n) but little complex to impl
    vector<int> topKFrequent3(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(auto& n:nums)
            count[n]++;
        
        unordered_map<int,vector<int>> freq;
        
        for(auto& [n,c]:count)
        {
            freq[c].push_back(n);
        }
        vector<int> result;
        for(int i=nums.size() ;i>0;--i)
        {
            if(freq.count(i))
            {
                result.insert(result.end(),begin(freq[i]),end(freq[i]));
                if(result.size()>=k)
                    break;
            }
        }
        
        return result;
    }
    
    //quick-select: 20ms
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto n:nums)
            mp[n]++;
        vector<int> t;
        for(auto it:mp)
            t.push_back(it.first);
        if(k==t.size())
            return t;
        int l=0,r=t.size()-1;
        while(true)
        {
            int p = partition(t,l,r,mp);
            if(p==k-1)          break;
            else if(p>k-1)      r = p-1;
            else                l = p+1;
        }
        t.resize(k);
        return t;
        
    }
    
    int partition(vector<int>& v,int l, int r,unordered_map<int,int>& mp)
    {
        int pivot = l;
        ++l;
        while(l<=r)
        {
            if(mp[v[l]]< mp[v[pivot]] && mp[v[r]] > mp[v[pivot]])
                swap(v[l++],v[r--]);
            else if(mp[v[l]] >= mp[v[pivot]])     ++l;
            else if(mp[v[r]] <= mp[v[pivot]])     --r;
        }
        swap(v[r],v[pivot]);
        return r;
    }
    
};

