class Solution {
public:
    int pivotInteger1(int n) {
        int sum = n*(n+1)/2;
        int prev = 0;
        for(int i=1;i<=n;++i){
            sum -=i;
            if(sum == prev) return i;
            prev += i;
        }
        return -1;
    }
    // math
    int pivotInteger(int n) {
        const int sum = (n * (n + 1) / 2);
        const int pivot = sqrt(sum);
        // If pivot * pivot is equal to sum (pivot found) return pivot, else return -1
        return pivot * pivot == sum ? pivot : -1;
  }
    // binary search
    int pivotInteger2(int n) {
    
        int left = 1, right = n;
        int totalSum = n * (n + 1) / 2;
        while (left < right) {
            int mid = (left + right) / 2;
​
            if (mid * mid - totalSum < 0) {
                left = mid + 1; 
            } else {
                right = mid;
            }
        }
        if (left * left - totalSum == 0) {
            return left;
        } else {
            return -1;
        }
    }
};
