class Solution {
public:
    // 267 ms
    vector<int> findSubstring(string s, vector<string>& words) {
        int wn = words.size();
        int wl = words[0].size();
        int sublen = wn*wl;
        int n = s.size();
        vector<int> indexes;
        if(n<sublen)
            return indexes;
        vector<int> wstart(n,-1);
      
        unordered_map<string, int> count;
        for(int i=0;i<wn;++i) {
            string& w = words[i];
           
            count[w]++;
            if(count[w]==1) { // finding str first time, search in s
                std::string::size_type k=s.find(w);
                while(k != std::string::npos){
                    wstart[k] = i;
                    k=s.find(w,k+1);
                }   
            }
        }
        
        // start location
        for (int i = 0; i < n - sublen + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            int pos = i;
            for (; j < wn; j++) {
                if(wstart[pos] == -1)
                    break;
                string& ss = words[wstart[pos]];
                seen[ss]++;
                if(seen[ss]> count[ss])
                    break;
                pos +=wl;
            }
            if (j == wn) indexes.push_back(i);
        }
        
        return indexes;
    }
};
​
