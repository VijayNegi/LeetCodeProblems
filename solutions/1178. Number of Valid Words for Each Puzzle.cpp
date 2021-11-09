class Solution {
public:
    // optimized
        vector<int> findNumOfValidWords1(vector<string>& words, vector<string>& puzzles) {
        int sw = words.size();
        int sp = puzzles.size();
        vector<int> iw(sw,0);
        vector<int> ip(sp,0);
        vector<vector<int>> cbuckets(26);
        
        for(int i=0;i!=sw;++i)
        {
            for(const auto& c:words[i])
            {
                int pos = c -'a';
                iw[i] |= 1<<pos;
            }
            
        }
        
        for(int i=0;i!=sw;++i)
        {
            for(int j = 0; j!=26 ; ++j)
            {
                if(iw[i] & 1<<j)
                    cbuckets[j].push_back(iw[i]);
            }
            
        }
        
        for(int i=0;i!=sp;++i)
        {
            for(const auto& c:puzzles[i])
            {
                ip[i] |= 1<<(c-'a');
            }
        }
        vector<int> res(sp,0);
        // now search puzzles for every matching word
        for(int i=0;i!=sp;++i)
        {
            int count = 0;
            int firstChar = puzzles[i][0]-'a';
            for(int w:cbuckets[firstChar])
            {
​
                int x = w ^ ip[i];
                int y = x | ip[i];
                if(y != ip[i])
                   continue;
                ++count;
            }
            res[i] = count;
        }
        return res;
    }
    // from editorial
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int sw = words.size();
        int sp = puzzles.size();
        unordered_map<int,int> wordCount;
        
        function<int(const string&)> bitmask = [](const string& str)
        {
            int mask(0);
            for(const auto& c:str)
                mask |= 1<<(c -'a');
            return mask;
        };
        
        for(int i=0;i!=sw;++i)
            wordCount[bitmask(words[i])]++;
        
   
        vector<int> res;
        for(auto& puzzle: puzzles)
        {
            int first = 1<<(puzzle[0] - 'a');
            int count = wordCount[first];
            
            // Make bitmask but ignore the first character since it must always be there.
            int mask = bitmask(puzzle.substr(1));
            
            // iterate over the submask
            for (int submask = mask; submask; submask = (submask - 1) & mask) {
                count += wordCount[submask | first];  // add first character
            }
            res.push_back(count);
        }
​
        return res;
    }
};
