class Solution {
    set<string> res;
public:
    //  (( )( ) 
    void removeOpen(string s,int i, vector<int> inO,vector<int> inC)
    {
        //cout<<"rOpen "<<s<<endl;
        if(i>= inO.size())
        {
            removeClose(s,0,inO,inC);
        }
        else
        {
            int ii = inO[i];
            //ii += i;
            for(int k=s.size()-1;k>=ii;--k)
            {
                if(s[k]=='(')
                {
                    string p = s;
                     removeOpen(p.erase(k,1),i+1,inO,inC); 
                }
            }
        }
    }
    
    void removeClose(string s,int i, vector<int> inO,vector<int> inC)
    {
        //cout<<"rClose "<<s<<endl;
        if(i>= inC.size())
            res.insert(s);
        else
        {
            int ii = inC[i];
            ii -= i; // indexes are based on original string , so just compensating for it
            for(int k=0;k<=ii;++k)
            {
                if(s[k]==')')
                {
                    string p = s;
                    p.erase(k,1);
                     removeClose(p,i+1,inO,inC); 
                }
            }
        }
            
    }
    
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<int> opn;
        vector<int> clo;
