class Solution {
public:
    // 2d window sum : 725 ms
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int r=0;r<rows;++r)
            for(int c=1;c<cols;++c)
                matrix[r][c] += matrix[r][c-1];
        int result=0;
        for(int c1 =0;c1<cols;++c1)
            for(int c2=0;c2<=c1;++c2) {
                long colSum=0;
                unordered_map<int,int> sumSeen;
                sumSeen[colSum]++;
                for(int r=0;r<rows;++r){
                    colSum += matrix[r][c1] - ((c2-1)>=0? matrix[r][c2-1]:0); 
                    result+=sumSeen[colSum-target];
                    sumSeen[colSum]++;
                } 
            }
        return result;
    }
    
    int Sum(vector<vector<int>>& matrix, int i,int ii,int j,int jj )
    {
        return matrix[ii][jj] - matrix[ii][j-1]- matrix[i-1][jj] + matrix[i-1][j-1];
    }
    // old solution : 939 ms
    int numSubmatrixSumTarget1(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols=0;
        if(rows)
            cols = matrix[0].size();
        vector<vector<int>> pre(rows+1, vector<int>(cols+1,0));
        int result=0;
        int rowsum=0;
        for(int i=1; i<rows+1 ; i++)
        {
            rowsum=0;
            for(int j=1; j<cols+1; j++) {
                rowsum+=matrix[i-1][j-1];
                pre[i][j]+= rowsum;
                pre[i][j]+= pre[i-1][j];
            }
        }
        map<int,int> count;
        for(int i=1;i<rows+1;i++) {
            for(int ii=i; ii<rows+1; ii++) {
                count.clear();
                count[0]++;
                for(int j=1; j<cols+1; j++) {
                        int sum = Sum(pre,i,ii,1,j);
                        if(count.find(sum-target)!=count.end())
                           result+=count[sum-target]; 
                        count[sum]++;
                }
            }
        }
        return result;
    }
};
