    }
    int find(int x)
    {
        if(parent[x] == x)          // x is itself the parent of the component that it belongs to
            return x;
        return parent[x] = find(parent[x]); // update parent of x before returning for each call -path compression
​
    } 
    void unionsets(int x, int y)
    {
        int xx = find(x);
        int yy = find(y);
        if(xx == yy)
            return;     // both belong to same component
        parent[yy] = xx;
    }
};
class Solution {
public:
    // DSU
    bool equationsPossible1(vector<string>& equations) {
        DSU ds(26);
        for(auto e:equations) {
            if(e[1] == '=') 
                ds.unionsets(e[0]-'a', e[3]-'a');
        }
        for(auto e:equations) {
            if(e[1] == '!') 
                if(ds.find(e[0]-'a') == ds.find(e[3]-'a'))
                    return false;
        }
        return true;
    }
    // other simple impl
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (string e : equations)
            if (e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a');
        for (string e : equations)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }
​
    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};
