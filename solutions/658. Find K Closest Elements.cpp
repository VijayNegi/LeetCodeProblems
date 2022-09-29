class Solution {
public:
    vector<int> findClosestElements0(vector<int>& arr, int k, int x) {
        auto cmp = [&](int l,int r) {
            int al = abs(l-x);
            int ar = abs(r-x);
            if(al == ar) return l<r;
            return ar>al;
        };
        priority_queue<int,vector<int>,decltype(cmp)> pq(cmp);
        
        for(auto& p:arr){
            pq.push(p);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> result;
        while(pq.size()) {
            result.push_back(pq.top());
            pq.pop();
        }
        sort(begin(result),end(result));
        return result;
    }
        vector<int> findClosestElements1(vector<int>& arr, int k, int x) {
        
        int l=0,r=k-1;
        int maxdis = max (abs(arr[l]-x), abs(arr[r]-x));
        for(int i=k;i<arr.size();++i)
        {
            if(arr[i]-x>=maxdis)
                break;
            
            if(abs(arr[i]-x) < maxdis)
            {
                r=i;
                l=i-k+1;
                maxdis = max(abs(arr[l]-x), abs(arr[r]-x));
            }
           
        }
        vector<int> result(begin(arr)+l,begin(arr)+r+1);
        return result;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left=0,right=arr.size()-k;
        while(left<right)
        {
            int mid = (left+right)/2;
            if(x-arr[mid] > arr[mid+k]-x)
                left=mid+1;
            else
                right = mid;
        }
        return vector<int>(arr.begin()+left,arr.begin()+left+k);
    }
};
