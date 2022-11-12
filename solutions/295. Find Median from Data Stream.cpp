class MedianFinder {
    priority_queue<int> high;
    priority_queue<int,vector<int>,greater<int>> low;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) { 
        if(low.size() != high.size()) {
            low.push(num);
            high.push(low.top());
            low.pop();
        }
        else {
            high.push(num);
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        double result = 0;
        if(high.size() == low.size())
            result = (high.top() + low.top())/2.0;
        else
            result = low.top();
        return result;
    }
};
​
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
