class Solution {
public:
    // self : 230ms
    vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](vector<int>& l,vector<int>& r){
                        if(l[0]==r[0])
                            return l[1]<r[1];
                        return l[0]>r[0];
        });
        vector<vector<int>> result;
        for(auto& p:people) {
            result.insert(next(result.begin(), p[1]),p);
        }
        return result;
    }
    // self prev : 77ms
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list<pair<int,int>> _sort;
        int size = people.size();
        vector<vector<int>> result(size,vector(2,-1));
        sort(people.begin(),people.end());
        int lastHeight=-1;
        int sub = 0;
        for(int i=0;i<people.size();i++)
        //for(vector<int> p : people)
        {
            vector<int> p = people[i];
            int loc=0,fre=0;
            if(p[0]==lastHeight)
                sub--;
            else
                sub = 0;
            
            int add = 1 + sub;
            while(fre!=p[1]+add)
            {
                if(result[loc++][0]==-1)
                    fre++;
            }
            lastHeight = p[0];
            result[loc-1] = p;
        }
        
        return result;
    }
};
