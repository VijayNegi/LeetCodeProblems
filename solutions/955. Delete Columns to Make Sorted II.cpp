            int j;
            bool next = false;
            vector<int> temp(strn,false); 
            for(j=1;j<strs.size();++j) {
                if(skip[j])
                    continue;
                if( strs[j][i] <= strs[j-1][i]) {
                    next = true;
                    if( strs[j][i] < strs[j-1][i]) {
                        ++result;
                        break;
                    }
                }
                else
                    temp[j] = true;
            }
            if(j==strn) {   // comparison result of this position only matters if this position was not removed 
                for(int t=1;t<strn;++t) {
                    skip[t] = skip[t] || temp[t]; 
                }     
            }  
            if(!next)   //  already lexicographic
                break;
        }
        return result;
    }
    // just cleaner: 6ms
    int minDeletionSize(vector<string>& A) {
        int res = 0, n = A.size(), m = A[0].length(), i, j;
        vector<bool> sorted(n - 1, false);
        for (j = 0; j < m; ++j) {
            for (i = 0; i < n - 1; ++i) {
                if (!sorted[i] && A[i][j] > A[i + 1][j]) {
                    res++;
                    break;
                }
            }
            if (i < n - 1) continue;
            for (i = 0; i < n - 1; ++i) {
                sorted[i] = sorted[i] || A[i][j] < A[i + 1][j];
            }
        }
        return res;
    }
​
};
