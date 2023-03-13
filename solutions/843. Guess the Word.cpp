/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int n = words.size();
        vector<vector<int>> mem(n,vector<int>(n,0));
        vector<int> overlap(n,0);
        for(int i=0;i<n;++i){
            mem[i][i] = 6;
            for(int j=i+1;j<n;++j){
                int val = comp(words[i],words[j]);
                mem[i][j] = mem[j][i] = val;
                overlap[i]+= val;
                overlap[j]+= val;
            }
        }
        vector<pair<int,int>> order;
        for(int i=0;i<n;++i)
            order.push_back({overlap[i],i});
        sort(order.begin(),order.end(),greater());
        set<int> candidate;
        for(int i=0;i<n;++i)
            candidate.insert(i);
        int k=0;
        while(candidate.size()){
            while(k<n && !candidate.count(order[k].second)) ++k;
            int s = order[k].second;
            int g = master.guess(words[s]);
            //cout<<words[s]<<" "<<overlap[s]<<" "<<g<<" ss="<<candidate.size()<<endl;
            if(g==6) return;
            for(int i=0;i<n;++i){
                if(i!=s){
                    if(mem[s][i]!=g) // if(mem[s][i] < g || (g==0 && mem[s][i]>0)) // secret is g distance away from word
                        candidate.erase(i);
                }
            }
            candidate.erase(s);
        }
        
    }
    int comp(string& s1,string& s2){
        int res=0;
        for(int i=0;i<6;++i)
            if(s1[i]==s2[i]) ++res;
        return res;
    }
};
