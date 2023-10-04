const int b = 1049; // prime
class MyHashMap {
    vector<vector<vector<int>>> buckets{b};
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int buck = key % b;
        bool already = false;
        for(auto& k:buckets[buck])
            if(k[0]==key){
                already = true;
                k[1] = value;
            }
        if(!already)
            buckets[buck].push_back({key,value});
    }
    
    int get(int key) {
        int buck = key % b;
        int result = -1;
         for(auto& k:buckets[buck])
            if(k[0]==key){
                result = k[1];
            }
        return result;
    }
    
    void remove(int key) {
        int buck = key % b;
        int n = buckets[buck].size();
        bool found = false;;
        for(int i=0;i<buckets[buck].size();++i){
            if(buckets[buck][i][0] == key){
                found = true;
                swap(buckets[buck][i],buckets[buck][n-1]);
            }
        }
        if(found)
            buckets[buck].resize(n-1);
        
    }
    
};
​
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
