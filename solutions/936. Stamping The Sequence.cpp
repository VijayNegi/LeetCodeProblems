class Solution {
public:
    //https://leetcode.com/problems/stamping-the-sequence/discuss/285844/C%2B%2B-Very-Short-No-extra-space-(except-for-answer)-Beats-100100-(16ms-9mb)
    vector<int> movesToStamp(string stamp, string target) {
        int NS = stamp.size(), NT = target.size();
        vector<int> ans;
        bool has_match;
        do {
            has_match = false;
            for(int i=0;i<=NT-NS;i++) {
                bool ok = true;
                int num_dot = 0;
                for(int j=0;j<NS;j++) { 
                    if(target[i+j]=='.')num_dot++; // take care we don't match only matched ones
                    if(target[i+j]!='.' && stamp[j]!=target[i+j]) { // simple wildcard matching 
                        ok=false;
                        break;
                    }
                }
                if(ok && num_dot<NS) {
                    has_match = true;
                    ans.push_back(i);
                    for(int j=0;j<NS;j++) target[i+j]='.';
                }
            }
​
        } while(has_match);
        for(char a:target)if(a!='.')return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
