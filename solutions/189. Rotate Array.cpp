class Solution {
public:
    int gcd (int a, int b) 
    {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }
    void rotate1(vector<int>& nums, int k) {
        
        int n = nums.size();
        k%=n;
        while(k>0)
        {
            int p = k;
            
            while(gcd(n,p)!=1)
                --p;
            k -=p;
            
            int idx = (p)%n;
            int value = nums[0];
            int counter = n;
            while(counter-->=0)
            {
                swap(nums[idx],value);
                idx = (idx+p)%n;
            }
        }
        return;
    }
    
    void reverse(vector<int>& nums, int start, int end) 
    {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    // move k elements back of array but both part (0-k) and (k+1,n) will be reversed , so reverse them back;
    void rotate(vector<int>& nums,int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
        
        
    }
};
