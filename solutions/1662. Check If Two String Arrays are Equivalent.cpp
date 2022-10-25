class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        int i1=0,i2=0;
        int j1=0,j2=0;
        while(i1< n1 && i2 <n2){
            if(word1[i1][j1]!= word2[i2][j2])
                return false;
            ++j1,++j2;
            if(j1 >= word1[i1].size()) {
                j1=0;
                ++i1;
            }
            if(j2>= word2[i2].size()) {
                j2=0;
                ++i2;
            }
        }
        return i1==n1 && i2==n2;
    }
};
