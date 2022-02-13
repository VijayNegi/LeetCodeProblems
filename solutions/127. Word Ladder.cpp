class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        std::unordered_set<std::string> wordlistSet;
        
        for(auto word : wordList) {
            wordlistSet.insert(word);
        }
        std::unordered_set<std::string> nextSet;
        std::unordered_set<std::string> currSet;
        currSet.insert(beginWord);
        int count = 1;
        string current_word = beginWord;
        int n = beginWord.size();
        while(!currSet.empty())
        {
            for(auto s : currSet)
            {
                for(int i = 0; i < n; ++i) 
                {
                    string temp = s;
                    for(int j = 0; j < 26; ++j) 
                    {
                        temp[i] = 'a' + j;
                        auto it = wordlistSet.find(temp);
                        if(it != wordlistSet.end()) 
                        {
                            if(temp == endWord)
                                return count+1;
                            nextSet.insert(temp);
                            wordlistSet.erase(temp); //it
                        }
                    }
                }
            }
        
            ++count;
            currSet = nextSet;
            nextSet.clear();
        }
        
        return 0;
    }
};
