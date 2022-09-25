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
