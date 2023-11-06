class SeatManager {
    // Marker to point to unreserved seats.
    int marker;
    // Sorted set to store all unreserved seats.
    set<int> available;
public:
    SeatManager(int n) {
        marker = 1;
        // while(n>0)
        //     available.insert(n--);
    }
    
    int reserve() {
        if(available.size()){
            int seat = *available.begin();
            available.erase(seat);
            return seat;
        }
        return marker++;
    }
    
    void unreserve(int seatNumber) {
        if(seatNumber + 1 == marker)
            --marker;
        else
            available.insert(seatNumber);
    }
};
​
/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
