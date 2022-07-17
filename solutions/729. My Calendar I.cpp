class MyCalendar {
    set<pair<int,int>> s;
    map<int,int>events;
public:
    MyCalendar() {
        
    }
    // set solution
    bool book1(int start, int end) {
        auto it = s.lower_bound({start,end});
        if(it != s.end() && it->first < end)
                return false;
        if(it!=s.begin() && (--it)->second > start)
            return false;
        s.insert({start,end});
        return true;
    }
    // map solution
    bool book(int start, int end) {  
        // Another nice solution
        auto next = events.upper_bound(start);
        if(next != events.end() &&   (*next).second < end)return false;
        events.insert({end,start});
        return true;
    }
};
​
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
