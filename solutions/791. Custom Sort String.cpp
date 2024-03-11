class Solution {
public:
    string customSortString1(string order, string str) {
        vector<int> map(26,0);
        
        for(const auto& c:str)
        {
            map[c-'a']++;
        }
        string result;
        for(const auto& c:order)
        {
            if(map[c-'a'])
            {
                result.append(map[c-'a'], c);
                map[c-'a'] = 0;
            }
        }
        
        for(int idx=0;idx<26;++idx)
        {
            if(map[idx])
            {
                result.append(map[idx], 'a'+idx);
            }
        }
        return result;
    }
    string customSortString(string order, string str) {
      vector<int> order_list(26, 26);
      int idx = 0;
      for(auto c : order){
        order_list[c - 'a'] = idx;
        idx ++;
      }
      
      sort(str.begin(), str.end(), [&order_list](char a, char b){
        return order_list[a - 'a'] < order_list[b - 'a'];
      });
        
      return str;
    }
};
