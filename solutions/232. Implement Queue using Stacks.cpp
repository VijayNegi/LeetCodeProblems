class MyQueue {
    vector<int> stk1,stk2;
    void suffle(){
        if(!stk1.size()){
            while(stk2.size()){
                stk1.push_back(stk2.back());
                stk2.pop_back();
            }
        }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stk2.push_back(x);
    }
    
    int pop() {
        suffle();
        int val = stk1.back();
        stk1.pop_back();
        return val;
    }
    
    int peek() {
        suffle();
        return stk1.back();
    }
    
    bool empty() {
        suffle();
        return !stk1.size();
    }
};
​
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
