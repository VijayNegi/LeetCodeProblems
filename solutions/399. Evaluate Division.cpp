class Solution {
public:
    unordered_map<string,vector<pair<string,double>>> mval;
    vector<double> result;
    unordered_map<string, int> visited;
    
    double dfs(string start, string end)
    {
        cout<<"->"<<start<<" - "<< end<<endl;
        double res = -1;
        if(!mval.count(start))
            return -1;
        if(start==end)
            return 1;
        if(!visited.count(start) )
        {
            auto vdest = mval[start];
            visited[start] = 1;
            
            for(auto dest : vdest)
            {
                if(dest.first==end)
                {
                    res = dest.second;
                }
                else if(dest.first!=end)
                {
                    double res1 = dest.second;
                    res1 *= dfs(dest.first,end);
                    if(res1>0)
                    {
                        res = res1;
                    }
                }
            }
        }
        else
        {
            res = -1;
        }
        cout<< " res - "<< res<<endl;
        return res;
    }
    // old dfs solution
    vector<double> calcEquation1(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        mval.clear();
        result.clear();
        
        for(int i=0; i<equations.size(); i++)
        {
            mval[equations[i][0]].push_back({equations[i][1],values[i]});
            mval[equations[i][1]].push_back({equations[i][0],1/values[i]});
        }
        
        for(int i=0;i<queries.size();i++)
        {
            visited.clear();
            double ans = dfs(queries[i][0],queries[i][1]);
            if(ans >= 0)
                result.push_back(ans);
            else
                 result.push_back(-1);
        }
        
        return result;
    }
    // Floyd Warshall 0 ms
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = values.size();
        unordered_map<string,int> strid;
        int idx = 0;
        // convert string to index
        for(int i=0;i<n;++i)
        {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
            if(strid.count(s1)==0)
                strid[s1] = idx++;
            if(strid.count(s2)==0)
                strid[s2] = idx++;
        }
        // fill initial values
        vector<vector<double>> dp(idx, vector(idx,-1.0));
        for(int i=0;i<n;++i)
        {
            string s1 = equations[i][0];
            string s2 = equations[i][1];
             // fill dp
            dp[ strid[s1] ][ strid[s2] ] = values[i];
            dp[ strid[s2] ][ strid[s1] ] = 1/values[i];
         }
        // Floyd Warshall
        for(int k=0;k<idx;++k)
            for(int i=0;i<idx;++i)
                for(int j=0;j<idx;++j)
                {
                    if(dp[i][k] <0 || dp[k][j] <0 || dp[i][j]>=0)
                        continue;
                    dp[i][j] = dp[i][k] * dp[k][j];
                    dp[j][i] = 1/dp[i][j];
                }
        // answer queries
        vector<double> result;
        for(auto q:queries)
        {
            string s1 = q[0];
            string s2 = q[1];
            
            if(strid.count(s1) ==0 || strid.count(s2)==0)
            {
                result.push_back(-1);
                continue;
            }
            result.push_back( dp[ strid[s1] ][ strid[s2] ]);
        }
        
        return result;
    }
};
