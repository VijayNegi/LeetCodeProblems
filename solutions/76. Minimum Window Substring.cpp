// https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
class Solution {
public:
    string minWindow1(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        int dict[128]={0};
        
        for(int i=0;i<tlen;++i)
            ++dict[t[i]];
        
        int start=0,end=0,begin,len = INT_MAX;
        
        while(end<slen)
        {
            if(dict[s[end]]>0)
                --tlen;
            --dict[s[end]]; // values not in t will become negative
            ++end;
            while(tlen==0) // found a match
            {
                if(len>end-start)
                {
                    begin = start;
                    len = end-start;
                }
                
                ++dict[s[start]];
                if(dict[s[start]]>0) // if it was in t it will become postive
                    ++tlen;
                ++start;
            }
        }
        
        string result;
        if(len<=slen)
            result = s.substr(begin,len);
        return result;
    }
    
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), begin=0, end=0, d=INT_MAX, head=0;
        while(end<s.size()){
            if(map[s[end++]]-->0) counter--; //in t
            while(counter==0){ //valid
                if(end-begin<d)  d=end-(head=begin);
                if(map[s[begin++]]++==0) counter++;  //make it invalid
            }  
        }
        return d==INT_MAX? "":s.substr(head, d);
    }
​
};
