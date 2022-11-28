class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_set<int> win,loss,moreloss;
        for(auto& m:matches){
            if(!win.count(m[0]) && !loss.count(m[0]) && !moreloss.count(m[0]))
                win.insert(m[0]);
            
            if(!win.count(m[1]) && !loss.count(m[1]) && !moreloss.count(m[1]))
                loss.insert(m[1]);
            else if(win.count(m[1])){
                win.erase(m[1]);
                loss.insert(m[1]);
            }
            else if(loss.count(m[1])){
                loss.erase(m[1]);
                moreloss.insert(m[1]);
            }
        }
        vector<vector<int>> result;
        result.push_back(vector(win.begin(),win.end()));
        result.push_back(vector(loss.begin(),loss.end()));
        sort(result[0].begin(),result[0].end());
        sort(result[1].begin(),result[1].end());
        return result;
    }
};
