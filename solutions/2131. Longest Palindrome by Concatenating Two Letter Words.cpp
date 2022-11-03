class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> seen;
        int result=0;
        for(auto& w:words){
            string r = w;
            r[0] = w[1],r[1]= w[0];
            if(seen[r]){
                result += 4;
                seen[r]--;
            }
            else
                seen[w]++;
        }
        for(auto& s:seen){
            if(s.second ==1 && (s.first[0] == s.first[1])){
                result+=2;
                break;
            }
        }
        return result;
    }
};
