using pis = pair<int,string>;
class TimeMap {
    unordered_map<string,vector<pis>> dict;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int ts) {
        if(!dict.count(key)) 
            dict[key].push_back({0,""});
        dict[key].push_back({ts,value});
    }
    
    string get(string key, int ts) {
        auto& vi  = dict[key];
        if(vi.size()==0)
            return "";
        auto it = upper_bound(begin(vi), end(vi),ts, [](int value, pis& val){
              return value < val.first;
          });
        it = prev(it);
        return it->second;
    }
};
​
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
