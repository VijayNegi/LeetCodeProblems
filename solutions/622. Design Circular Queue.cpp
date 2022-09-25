/*
//39 ms
struct Node{
    int val;
    Node *front,*rear;
    Node(int _val,Node* _f,Node* _r)
        :val(_val),front(_f),rear(_r){}
};
class MyCircularQueue {
    int maxSize;
    int s;
    Node *start,*end;
    
public:
    MyCircularQueue(int k) {
        start=end= new Node(0,nullptr,nullptr);
        start->front = start;
        start->rear = start;
        maxSize = k;
        s=0;
        for(int i=1;i<k;++i){
            Node* temp = new Node(0,start,end);
            start->rear = temp;
            end->front = temp;
            end = temp;
        }
        end=start;
    }
    
    bool enQueue(int value) {
        if(s>=maxSize)
            return false;
        end->val = value;
        end = end->rear;
        ++s;
        return true;
    }
    
    bool deQueue() {
        if(s==0)
            return false;
        start = start->rear;
        --s;
        return true;
    }
    
    int Front() {
        if(s==0)
            return -1;
        return start->val;
    }
    
    int Rear() {
        if(s==0)
            return -1;
        return end->front->val;
    }
    
    bool isEmpty() {
        return s==0;
    }
    
    bool isFull() {
        return s==maxSize;
    }
};
*/
// 66 ms
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data.resize(k);
        maxSize = k;
    }
    bool enQueue(int val) {
        if (isFull()) return false;
        tail = (tail + 1) % maxSize;
        data[tail] = val;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        if (head == tail) head = 0, tail = -1;
        else head = (head + 1) % maxSize;
        return true;
    }
    int Front() {
        return isEmpty() ? -1 : data[head];
    }
    int Rear() {
        return isEmpty() ? -1 : data[tail];
    }
    bool isEmpty() {
        return tail == -1;
    }
    bool isFull() {
        return !isEmpty() && (tail + 1) % maxSize == head;
    }
private:
    int maxSize, head = 0, tail = -1;
    vector<int> data;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
