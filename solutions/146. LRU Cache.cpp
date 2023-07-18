#if 0 
class LRUCache {
    int size;
    unordered_map<int,list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> used;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cache.count(key))
        {
            auto it = cache[key];
            int value = (*it).second;
            used.erase(it);
            used.push_front({key,value});
            cache[key] = used.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // find key in map, yes, update it
        // if not already in map, check size, 
        // less then size put in cache
        // size more then remove least recently use put.
        if(cache.count(key))
        {
            used.erase(cache[key]);
            used.push_front({key,value});
            cache[key] = used.begin();
            
        }
        else
        {
            if(used.size()==size)
            {
                auto k = used.back();
                used.pop_back();
                cache.erase(k.first);
            }
            
            used.push_front({key,value});
            cache[key] = used.begin();
        }
    }
};

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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
