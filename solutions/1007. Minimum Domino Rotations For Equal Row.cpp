class Solution {
public:
    //108 ms
    int minDominoRotations1(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> freqt(7,0),freqb(7,0);
        for(auto& n :  tops)
            ++freqt[n];
        for(auto& n : bottoms )
            ++freqb[n];
        int face= -1;
        int maxf = 0;
        for(int i=1;i<=6;++i)
            if(freqt[i]+freqb[i]>maxf)
            {
                maxf = freqt[i]+freqb[i];
                face = i;
            }
        
        if(maxf<n)
            return -1;
        int result=0;
        
        for(int i=0;i<n;++i)
        {
            if(tops[i]!=face && bottoms[i]!=face )
                return -1;
            if(freqt[face]>freqb[face])
            {
                if(tops[i]!=face)
                {
                    if(bottoms[i]==face)
                        ++result;
                }
            }
            else
            {
                if(bottoms[i]!=face)
                {
                    if(tops[i]==face)
                        ++result;
                }
            }
        }
        return result;
    }
    // 230ms
    int minDominoRotations2(vector<int>& A, vector<int>& B) {
        int n = A.size();
        if(n==1)
            return 0;
        vector<int> faceCount(7,0);
        for(int i=0;i<n;i++)
        {
            faceCount[A[i]]++;
            faceCount[B[i]]++;
        }
        int Max = 0;
        for(int i=0;i<faceCount.size();i++)
            Max = (faceCount[Max]<faceCount[i])? i: Max;
       
        if(n>faceCount[Max])
            return -1;
        int result(0);
        for(int i=0;i<n;i++)
        {
            if(A[i]!= Max && B[i]!=Max)
                return -1;
            if(A[i] != Max)
                result++;
        }

        result = min(result,n - (faceCount[Max]- (n-result)) );
        return result;
    }
    // 211 ms
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> countA(7), countB(7), same(7);
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            countA[A[i]]++;
            countB[B[i]]++;
            if (A[i] == B[i])
                same[A[i]]++;
        }
        for (int i  = 1; i < 7; ++i)
            if (countA[i] + countB[i] - same[i] == n)
                return n - max(countA[i], countB[i]);
        return -1;
    }

};
