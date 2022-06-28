class Solution {
public:
    // self
    int minDeletions1(string s) {
        vector<int> freq(26,0);
        for(auto& c:s) {
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        unordered_set<int> ss;
        int result = 0;
        for(int i=0;i<26;++i) {
            if(freq[i]==0)
                continue;
            if(ss.count(freq[i])==0) {
                ss.insert(freq[i]);
            }
            else {
                int org = freq[i];
                while(org>0 && ss.count(org)==1)
                    org--;
                ss.insert(org);
                result += freq[i]-org;
            }
        }
        return result;
    }
    // cleaner
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int count = 0;
        unordered_set<int> seenFrequencies;
        for (int i = 0; i < 26; i++) {
            while (freq[i] && seenFrequencies.find(freq[i]) != seenFrequencies.end()) {
                freq[i]--;
                count++;
            }
            seenFrequencies.insert(freq[i]);
        }
        return count;
    }
};
