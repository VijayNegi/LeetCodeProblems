class Solution {
public:
   vector<int>* precursor;
	vector<vector<string>> res;
	bool isANeighbor(string& s1, string& s2) {
		bool hasChanged = false;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] != s2[i]) {
				if (hasChanged)
					return false;
				else
					hasChanged = true;
			}
		}
		return true;
	}
	void generateRoute(vector<string> right, vector<int>& precursor2, vector<string>& wordList) {
		if (precursor2.size() == 0) {
			res.push_back(right);
			return;
		}
		vector<string> copy;
		for (int i = 0; i < precursor2.size(); i++) {
			copy = right;
			// insert before the begin() cause we are back-tracing.
			copy.insert(copy.begin(), wordList[precursor2[i]]);
			generateRoute(copy, precursor[precursor2[i]], wordList);
		}
	
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		wordList.push_back(beginWord);
		int size = wordList.size();
		vector<int>* neighbors = new vector<int>[size];
		int ewordindex = -1;
		for (int i = 0; i < size; i++) {
			if (wordList[i] == endWord)
				ewordindex = i;
			for (int j = i + 1; j < size; j++) {
				if (isANeighbor(wordList[i],wordList[j])) {
					neighbors[i].push_back(j);
					neighbors[j].push_back(i);
				}
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
                cnt++ ;
            }
        }
        return cnt == 1 ;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.insert(wordList.begin(), beginWord);
        for(int i = 1 ; i < wordList.size() ; i++)
        {
            if(wordList[i] == wordList[0]) // string compare
            {
                wordList[i] = wordList.back() ;
                wordList.pop_back() ;
                break ;
            }
        }
        map<string, int> wti ; // word to index
        for(int i = 0 ; i < wordList.size() ; i++)
        {
            wti.insert({wordList[i], i}) ;
        }
        if(!wti.count(endWord)) 
        {
            return {} ;
        }
        vector<vector<int>> edges(wti.size()) ;
        for(int i = 0 ; i < wordList.size() ; i++)
        {
            for(int j = 0 ; j < wordList.size() ; j++)
            {
                if(i != j)
                {
                    if(neighbour(wordList[i], wordList[j]))
                    {
                        edges[i].push_back(j) ;
                    }
                }
            }
        }
        // BFS  
        int start_node = 0 , target_node = wti[endWord] , r = 0 , min_step = INT_MAX ;
        vector<int> vis(wordList.size(), INT_MAX) ;   
        vis[start_node] = 0 ;
        queue<int> q ;   
        q.push(start_node) ;
        while(!q.empty())
        {
            int sz  = q.size() ;
            for (int i = 0 ; i < sz ; i++)
            {
                int fr = q.front() ;  
                q.pop() ;
                if(fr == target_node)
                {
                    min_step = min(min_step , r) ;
                }
                for(int j = 0 ; j < edges[fr].size() ; j++)
                {
                    int update_node = edges[fr][j] ;
                    if(r + 1 < vis[update_node])
                    {
                        vis[update_node] = r + 1 ;
                        q.push(update_node);
                    }
                }
            }
            r++ ;
        }
        if(min_step == INT_MAX)
        {
            return {} ;
        }
        queue<vector<string>> q2 ; 
        q2.push({wordList[target_node]}) ;
        r = min_step ;
        while(r)
        {
             int sz  = q2.size() ;
             for(int i = 0 ; i < sz ; i++)
             {
                vector<string> seq = q2.front() ;
                q2.pop();
                string back = seq.back() ;
                int curr = wti[back] ;
                for (int j = 0 ; j < edges[curr].size() ; j++)
                {
                    int new_node = edges[curr][j] ;
                    if (vis[new_node] == r - 1)
                    {
                        seq.push_back(wordList[new_node]) ;
                        q2.push(seq) ;
                        seq.pop_back() ;
                    }
                }
            }
            r-- ;
        }
        vector<vector<string>> ans;
        while(!q2.empty())
        {
            vector<string> temp = q2.front() ;
            q2.pop() ;
            reverse(begin(temp) , end(temp)) ;
            ans.push_back(temp) ;
        }
        return ans ;
    }
};
*/
