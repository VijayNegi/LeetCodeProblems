class MyStack {
    queue<int> q1,q2; 
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int res = top();
        q1.pop();
        swap(q1,q2);
        return res;
    }
    
    int top() {
        while(q1.size()>1)
        {
            q2.push( q1.front());
            q1.pop();
        }
        return q1.front();
    }
    
    bool empty() {
        return !q1.size();
    }
};
​
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
