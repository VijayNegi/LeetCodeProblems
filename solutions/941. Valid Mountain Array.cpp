class Solution {
public:
    bool validMountainArray1(vector<int>& arr) {
        int n = arr.size();
        if(n<3)
            return false;
        bool downhill = false;
        int count = 0;
        
        for(int i=1;i<n;++i)
        {
            if(!downhill && arr[i-1] < arr[i])
                count++;
            else if(!downhill && arr[i-1]> arr[i] && count)
            {
                ++count;
                downhill = true;
            }
            else if(downhill && arr[i-1] > arr[i])
                ++count;
            else
                break;
        }
        return downhill && (count +1 == n);
    }
    // 
     bool validMountainArray(vector<int>& A) {
        int n = A.size(), i = 0, j = n - 1;
        while (i + 1 < n && A[i] < A[i + 1]) i++;
        while (j > 0 && A[j - 1] > A[j]) j--;
        return i > 0 && i == j && j < n - 1;
    }
};
