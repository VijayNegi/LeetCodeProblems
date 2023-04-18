class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l=word1.size(),r=word2.size();
        int i=0,j=0;
        string result;
        while(i<l || j<r){
            if(i<l) result += word1[i++];
            if(j<r) result += word2[j++];
        }
        return result;
    }
};
