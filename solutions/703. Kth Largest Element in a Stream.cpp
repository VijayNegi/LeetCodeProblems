class KthLargest {
    multiset<int> s;
    int k;
public:
    KthLargest(int _k, vector<int>& nums):k(_k) {
        for(auto n:nums)
            add(n);
    }
    
    int add(int val) {
        s.insert(val);
        if(s.size()>k)
            s.erase(s.begin()); // Note: the iterator, for key , it will remove all keys
        return *(s.begin());
    }
};
/*
class KthLargest {
    int k;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto& n:nums)
        {
            pq.push(n);
            if(pq.size()>k)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k)
            pq.pop();
        return pq.top();
    }
};
*/
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
