struct Node{
    int l,r;
    int count,mcount;
    Node *left,*right;
    Node(int low,int high):l(low),r(high),mcount(0),count(0),left(nullptr),right(nullptr){
    }
    int update(int start,int end) {
        // if(end<l || start>r)
        //     return 0;
        
        if(start == l && end == r) {
            ++count;++mcount;
            return mcount;
        }
        int mid = l + (r-l)/2;
        if(left == nullptr){
            left = new Node(l,mid);
            right = new Node(mid+1,r);
        }
​
        if(end<=mid)
            mcount = max(mcount,left->update(start,end) + count);
        else if(start>mid)
            mcount = max(mcount,right->update(start,end) + count);
        else
            mcount = max(left->update(start,mid),right->update(mid+1,end) ) + count;
            
        return mcount;
    }
};
class MyCalendarThree {
    map<int,int> timeline;
    map<int,int> timeline1;
    int res{0};
    Node* sTree;
public:
    MyCalendarThree() {
        timeline = {{-1, 0}};
        sTree = new Node(0,1e9);
    }
    
    // 205 ms
    // Map Line Sweep
    int book1(int start, int end) {
        timeline1[start]++;
        timeline1[end]--;
        int ongoing=0,result=0;
        for(auto m:timeline1) {
            result = max(result, ongoing += m.second);
        }
