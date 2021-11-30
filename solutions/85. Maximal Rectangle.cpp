class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r = matrix.size();
        if(r==0)
            return 0;
        int c = matrix[0].size();
        
        
//         vector<vector<int>> matH(r,vector(c,0)),matV(r,vector(c,0));
        
//         for(int i=0;i<r;++i)
//         {
//             for(int j=0;j<c;++j)
//             {
//                 if(matrix[i][j] == '1')
//                 {
//                     matH[i][j] = 1;
//                     matV[i][j] = 1;
//                     if(i>0)
//                         matH[i][j] += matH[i-1][j];
//                     if(j>0)
//                         matV[i][j] += matV[i][j-1];
//                 }
//             }
//         }
        vector<int> sum(r,0);
        int maxarea = 0;
        
        for(int j=0;j<c;++j)
        {
            // calculate row sum till column
            for(int i=0;i<r;++i)
            {
                if(matrix[i][j] == '1')
                    ++sum[i];
                else
                    sum[i] = 0;
            }
            // now calculate area
            stack<int> s;
            for(int i=0;i<r;++i)
            {
                if(s.empty() || sum[s.top()] <= sum[i])
                    s.push(i);
                else
                {
                    while(!s.empty() && sum[s.top()]>sum[i])
                    {
                        int height = sum[s.top()];
                        s.pop();
                        int width = s.empty() ? i : i - s.top() -1 ;
                        maxarea = max(maxarea, height * width);
                        
                    }
                    s.push(i);
                }
                
                
            }
            while(!s.empty())
            {
                int height = sum[s.top()];
                s.pop();
                int width = s.empty() ? r :r- s.top()-1;
                maxarea = max(maxarea, height * width);
           
            }
        }
        
        return maxarea;
    }
};
