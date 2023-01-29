/*
// self : WA, not sure what is the issue , probabely with stable priority queue.
using pii = pair<int,int>;
class LFUCache {
    int s;
    int counter=0;
    unordered_map<int,pair<int,int>> dict;
    priority_queue<pii,vector<pii>,greater<>> q;
    void makeSpace(){
        while(q.size()){
            auto [freq, key] = q.top();q.pop();
            if(!dict.count(key) || dict[key].second != freq)
                continue;
            dict.erase(key);
            break;
        }
    }
    int getPriority(int p){ // for stable priority queue
        ++counter;
        return ((p<<10) + counter);
    }
public:
    LFUCache(int capacity) {
        s= capacity;
        //counter = 1<<9;
    }
    
    int get(int key) {
        
        if(!dict.count(key))
            return -1;
        dict[key].second = getPriority((dict[key].second >>10) +1);;
        q.push({dict[key].second, key});
        return dict[key].first;
    }
    
    void put(int key, int value) {
        if(dict.count(key)){
            dict[key].second = getPriority((dict[key].second >>10) +1);
            dict[key].first = value;
            q.push({dict[key].second, key});
            return;
        }
        if(dict.size() == s)
            makeSpace();
        //if(dict.size() == s)
        //    return;
        dict[key] = {value,getPriority(1)};
