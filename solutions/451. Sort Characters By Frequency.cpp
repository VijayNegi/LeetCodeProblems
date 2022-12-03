class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256,0);
        for(auto& a:s)
            freq[a]++;
        vector<pair<int,char>> charfreq;
        for(int i=0;i<256;++i)
            if(freq[i])
                charfreq.push_back({freq[i],i});
        sort(charfreq.begin(),charfreq.end(),greater());
        string result;
        for(auto& f: charfreq)
            result.append(f.first,f.second);
        return result;
    }
};
