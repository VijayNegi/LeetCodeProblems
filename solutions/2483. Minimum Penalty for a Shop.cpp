class Solution {
public:
    int bestClosingTime(string cust) {
        int pen=0;
        int time = cust.size();
        for(auto& c: cust)
            if(c=='N') ++pen;
        int curr = pen;
        for(int i = cust.size()-1;i>=0;--i){
            if(cust[i]=='N'){
                --curr;
                if(curr<=pen){
                    pen = curr;
                    time = i;
                }   
            }
            else
                ++curr;  
        }
        return time;
    }
};
