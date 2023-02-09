class Solution {
public:
    // self : TLE as suffix count can be any, we should group by first char as it can be max 26
    long long distinctNames1(vector<string>& ideas) {
        unordered_map<string,unordered_set<char>> pfix;
        for(auto& i:ideas){
            pfix[i.substr(1)].insert(i[0]);
        }
        long long result=0;
        auto it = pfix.begin();
        while(it != pfix.end()){
            auto it2 = next(it);
            while(it2!= pfix.end()){
                unordered_set<char> s(it->second);
                s.insert(it2->second.begin(),it2->second.end());
                int com = it->second.size() + it2->second.size() - s.size();
                result += 2LL * (it->second.size() - com) * (it2->second.size() - com);
                it2 = next(it2);
            }
            ++it;
        }
        return result;
    }
    // official
    long long distinctNames(vector<string>& ideas) {
        // Group idea by their initials.
        unordered_set<string> initialGroup[26];
        for (auto& idea : ideas)
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));
        
        // Calculate number of valid names from every pair of groups.
        long long answer = 0;
        for (int i = 0; i < 25; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                // Get the number of mutual suffixes.
                int numOfMutual = 0;
                for (auto& ideaA : initialGroup[i]) {
                    if (initialGroup[j].count(ideaA)) {
                        numOfMutual++;
                    }
                }
​
                // Valid names are only from distinct suffixes in both groups.
                // Since we can swap a with b and swap b with a to create two valid names, multiple answer by 2.
                answer += 2LL * (initialGroup[i].size() - numOfMutual) * (initialGroup[j].size() - numOfMutual);
            }
        }
        return answer;
    }
​
};
