class Solution {
public:
    //contest : 2ms
    int countPoints1(string rings) {
        vector<vector<int>> rods(10,vector<int>(3,0));
        
        for(int i=0;i<rings.size();i+=2)
        {   
            if(rings[i]=='R')
                rods[rings[i+1]-'0'][0] = true;
            else if(rings[i]=='G')
                rods[rings[i+1]-'0'][1] = true;
            else
                rods[rings[i+1]-'0'][2] = true;
        }
        int result = 0;
        for(auto v:rods)
        {
            if(v[0] && v[1] && v[2])
                ++result;
        }
        return result;
    }
    // using bitmask
    int countPoints(string rings) {
        int rods[10] = {};
        for (int i = 0; i < rings.size(); i += 2) {
            int color = rings[i] == 'R' ? 1 : rings[i] == 'G' ? 2 : 4;
            rods[rings[i + 1] - '0'] |= color;
        }
        return count(begin(rods), end(rods), 7);
    }
};
