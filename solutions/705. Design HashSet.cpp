class MyHashSet {
    bitset<1000001> bt;
public:
    MyHashSet() {
    }
    
    void add(int key) {
        bt[key] = 1;
    }
    
    void remove(int key) {
        bt[key] = 0;
    }
    
    bool contains(int key) {
        return bt[key];
    }
};
​
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
