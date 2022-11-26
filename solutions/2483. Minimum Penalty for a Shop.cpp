class Solution {
public:
    // self : 65 ms
    int bestClosingTime1(string cust) {
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
    // 24 ms
    int bestClosingTime(string customers) {
        int ans=0,maxVal=0,count=0;
​
        for(int i=0;i<customers.length();i++){
            if(customers[i] == 'Y') 
                count++;
            else 
                count--;
            if(count > maxVal){
                ans=i+1;
                maxVal = count;
            }
        }
        return ans;
    }
};
