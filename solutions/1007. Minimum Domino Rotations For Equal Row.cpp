class Solution {
public:
    // self
    int minDominoRotations1(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int> face(7,0);
        for(int i=0;i<n;++i){
            if(tops[i]==bottoms[i])
                face[tops[i]]++;
            else{
                face[tops[i]]++;
                face[bottoms[i]]++;
            }  
        }
        for(int i=1;i<7;++i){
            if(face[i]==n){
                int t=0,b=0;
                for(auto& k:tops) if(k==i) ++t;
                for(auto& k:bottoms) if(k==i) ++b;
                return min(n-t,n-b);
            }
        }
        return -1;
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
        for (int i  = 1; i < 7; ++i)
            if (countA[i] + countB[i] - same[i] == n)
                return n - max(countA[i], countB[i]);
        return -1;
    }
};
