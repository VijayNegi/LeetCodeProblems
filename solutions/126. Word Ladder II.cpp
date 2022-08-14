            }
        }
        vector<int> steps(size);//memorize distances
        queue<int> line;//BFS
        steps[size - 1] = 1;
        line.push(size - 1);//add the index of the beginWord to the queue
        precursor = new vector<int>[size];
        while (!line.empty()) {
            int pos = line.front();
            line.pop();
            if (wordList[pos] == endWord)
                //we stop here because we are looking for the shortest routes
                break;
            for (int i = 0; i < neighbors[pos].size(); i++) {
                if (steps[neighbors[pos][i]]==0) {
                    //we have never visited here
                    steps[neighbors[pos][i]] = steps[pos] + 1;
                    precursor[neighbors[pos][i]].push_back(pos);
                    line.push(neighbors[pos][i]);
                }
                else if (steps[neighbors[pos][i]] == steps[pos] + 1)
                    //there's another route to get here and it has the SAME distance
                    precursor[neighbors[pos][i]].push_back(pos);
            }
        
        }
        if (ewordindex == -1 || steps[ewordindex] == 0)
            return res;
        vector<string> right{endWord};
        generateRoute(right,precursor[ewordindex] , wordList);
        return res;
    }
};
/*
class Solution {
public:
    bool neighbour(string a, string b){
        int cnt = 0 ;
        for(int i = 0 ; i < a.length() ; i++)
        {
            if(a[i] != b[i])
            {
