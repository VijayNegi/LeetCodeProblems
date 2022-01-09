class Solution {
public:
    bool isRobotBounded1(string instructions) {
        
        int s[2] = {0};
        int d = 0;
        function<void(int*,int)> makemove = [](int* s,int d)
        {
            switch(d)
            {
                case 0: 
                    s[1]++;
                    break;
                case 1:
                    s[0]--;
                    break;
                case 2:
                    s[1]--;
                    break;
                case 3:
                    s[0]++;
                    break;
            }
        };
        
         function<int(int,int)> changedir = [](int d,int l)
         {
             if(l)
                 return (++d)%4;
             return (d+3)%4;
         };
        
        // why 4 because there are 4 directions and after at most 4 iterations we should be back at origin
        int k=4;
        while(k--)
        {
        
            for(auto c: instructions)
            {
                if(c=='G')
                    makemove(s,d);
                else
                    d = changedir(d,c=='L');
            }
            
            if((s[0] == 0 && s[1]==0) )
            return true;
        }
        
        return false;
    }
    
     bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        for (char & ins : instructions)
            if (ins == 'R')
                i = (i + 1) % 4;
            else if (ins == 'L')
                i = (i + 3) % 4;
            else
                x += d[i][0], y += d[i][1];
        return x == 0 && y == 0 || i > 0;
    }
};
