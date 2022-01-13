class UndergroundSystem {
    unordered_map<int,pair<string,int>> journy_start;
    unordered_map<string,pair<double,int>> journy_avg;
public:
    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
        journy_start[id] = make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        int travel_time = t - journy_start[id].second;
        string key = journy_start[id].first + "," + stationName;
        journy_avg[key].first += travel_time;
        journy_avg[key].second += 1;
        journy_start.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string key = startStation + "," + endStation;
        return journy_avg[key].first/ journy_avg[key].second;
    }
};
​
/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
