// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/861912/Sharing-My-Both-C%2B%2B-Sol.-Using-Binary-Search-Heap
class Solution {
public:
    int kthSmallest1(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        while(left<right)
        {
            int mid = left + (right-left)/2;
            int count = 0;
            int row = n-1;
            int col = 0;
            while(row>=0 && col<n)
            {
                if(matrix[row][col]<=mid)
                {
                    count += row + 1;
                    ++col;
                }
                else
                    --row;
            }
            if(count<k)
            {
                left = mid + 1;
            }
            else
                right = mid;
        }
        
        
        return left;
    }
    //https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1321834/C%2B%2B-Simple-Clean-and-Short-Binary-Search-Solution
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lo = matrix[0][0], hi = matrix[n-1][n-1] + 1, mid, count, tmp;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2, tmp = n - 1, count = 0;
            
            // For each row, we count the elements that are smaller then mid
            for (int i = 0; i < n; i++) {
                while (tmp >= 0 && matrix[i][tmp] > mid) tmp--;
                count += tmp + 1;
            }
            
            if (count < k) lo = mid + 1;
            else hi = mid;
        }
        
        return lo;
    }
};
