};
​
#endif
class LRUCache {
    map<int,int> time2key;
    unordered_map<int,pair<int,int>> key2timeval;
    int time{0};
    int maxsize;
public:
    LRUCache(int capacity) {
        maxsize = capacity;
    }
    
    int get(int key) {
        if(!key2timeval.count(key))
            return -1;
        auto& entry = key2timeval[key];
        time2key.erase(entry.first);
        entry.first = time++;
        time2key[entry.first] = key;
        return entry.second;
    }
    
    void put(int key, int value) {
        if(key2timeval.count(key)){
            auto& entry = key2timeval[key];
            time2key.erase(entry.first);
            entry.first = time++;
            entry.second = value;
            time2key[entry.first] = key;
        }
        else{
            pair<int,int> entry = {time++,value};
            key2timeval[key] = entry;
            time2key[entry.first] = key;
            if(key2timeval.size()>maxsize){
                auto itr = time2key.begin();
                key2timeval.erase(itr->second);
                time2key.erase(itr);
                
            }
        }
    }
};
​
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
