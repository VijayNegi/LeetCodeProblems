class Logger {
    unordered_map<string,int> lastseen;
public:
    Logger() {
        
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        
        if(!lastseen.count(message))
            lastseen[message] = -10;
        int prev = lastseen[message];
        if(timestamp -prev >= 10){
            lastseen[message] = timestamp;
            return true;
        }
        return false;
    }
};
​
/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
