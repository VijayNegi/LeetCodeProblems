class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> seq_len;
        int result=0;
        for(auto& n:arr){
            seq_len[n] = seq_len[n-difference]+1;
            result = max(result,seq_len[n]);
        }
        return result;
    }
};
