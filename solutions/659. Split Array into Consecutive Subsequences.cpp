class Solution {
public:
    // self 112 ms
    bool isPossible1(vector<int>& nums) {
        vector<int> freq(2002,0);
        for(auto& n:nums)
            freq[n+1000]++;
        vector<int> seq;
        for(auto& k: freq) {
            if( k > seq.size()) {
                seq.insert(seq.end(),k-seq.size(),0);
                for(auto& s: seq)
                    ++s;
            }
            else if(k == seq.size()) {
                for(auto& s: seq)
                    ++s;
            }
            else {
                for(int i=0;i<(seq.size()-k);++i)
                    if(seq[i]<3)
                        return false;
                int s = (seq.size()-k);
                for(int i=0; s<seq.size();++i,++s)
                    seq[i] = seq[s];
                seq.resize(k);
                for(auto& s: seq)
                    ++s;
            }
        }
        for(auto& s: seq)
                if(s<3)
                    return false;
        return true;
    }
    //https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106493/C%2B%2B-O(n)-solution-two-pass
    // 105 ms
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> cnt, tails;
        for(int &i : nums) cnt[i]++;
        for(int &i : nums){
            if(!cnt[i]) continue;
            cnt[i]--;
            if(tails[i-1] > 0){
                tails[i-1]--;
                tails[i]++;
            }
            else if(cnt[i+1] && cnt[i+2]){
                cnt[i+1]--;
                cnt[i+2]--;
                tails[i+2]++;
            }
            else return false;
        }
        return true;
    }
};
 
    
    
    
