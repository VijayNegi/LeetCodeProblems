// disjoint set union
class DJU
{
    public:
    vector<int> parent;
    vector<int> size;
    DJU(int n):parent(n),size(n,1)
    {
        for(int i=0;i!=n;++i)
            parent[i] = i;
    }
    
    int find(int x)
    {
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    
    void unionsets(int x, int y)
    {
        int xx = find(x);
        int yy = find(y);
        if(xx == yy)
            return;     // both belong to same component
        if(size[xx]> size[yy])
        {
            parent[yy] = xx;
            size[xx] += size[yy];
            size[yy] =0;
        }
        else
        {
            parent[xx] = yy;
            size[yy] += size[xx];
            size[xx] =0;
        }
        
    }
};
​
class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        DJU dj(n);
        unordered_map<int, vector<int>> primegroup;
        function<void(int)> pfactors = [&](int idx)
        {
            //vector<int> res;
            int x = nums[idx];
            if(x%2==0)
            {
                primegroup[2].push_back(idx);
                while(x%2==0)
                    x = x>>1;
            }
            for(int i=3;i<=sqrt(x);i+=2)
            {
