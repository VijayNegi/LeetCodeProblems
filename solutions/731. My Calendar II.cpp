class MyCalendarTwo {
    map<int,int> timeline;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        timeline[start]++;
        timeline[end]--;
        int count=0;
        for(auto v:timeline){
            count += v.second;
            if(count==3){
                timeline[start]--;
                timeline[end]++;
                return false;
            }
        }
        return true;
    }
};
​
/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
