class LRUCache {
    int size;
    unordered_map<int,list<pair<int,int>>::iterator> hmap;
    list<pair<int,int>> que;
public:
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(hmap.count(key))
        {
            auto it = hmap[key];
            int value = (*it).second;
            que.erase(it);
            que.push_front({key,value});
            hmap[key] = que.begin();
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // find key in map, yes, update it
        // if not already in map, check size, 
        // less then size put in cache
        // size more then remove least recently use put.
        if(hmap.count(key))
        {
            que.erase(hmap[key]);
            que.push_front({key,value});
            hmap[key] = que.begin();
            
        }
        else
        {
            if(que.size()==size)
            {
                auto k = que.back();
                que.pop_back();
                hmap.erase(k.first);
            }
            
            que.push_front({key,value});
            hmap[key] = que.begin();
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
