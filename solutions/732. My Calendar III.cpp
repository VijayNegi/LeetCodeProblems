struct Node{
    int l,r;
    int count,mcount;
    Node *left,*right;
    Node(int low,int high):l(low),r(high),mcount(0),count(0),left(nullptr),right(nullptr){
    }
    int update(int start,int end) {
        // if(end<l || start>r)
        //     return 0;
        
        if(start == l && end == r) {
            ++count;++mcount;
            return mcount;
        }
        int mid = l + (r-l)/2;
        if(left == nullptr){
            left = new Node(l,mid);
            right = new Node(mid+1,r);
        }

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
        return result;
    }
    // 80 ms
    //https://leetcode.com/problems/my-calendar-iii/discuss/176950/C++-Map-Solution-Fastest
    // Map Line Sweep optimized
    int book2(int s, int e) {
        //map<int, int> count = {{-1, 0}};
        auto start = timeline.emplace(s, (--timeline.upper_bound(s))->second);
        auto end = timeline.emplace(e, (--timeline.upper_bound(e))->second);
        for (auto i = start.first; i != end.first; ++i)
            res = max(res, ++(i->second));
        return res;
    }
    // dynamic segment tree : 476 ms
    // solution with lazy loading :
    // https://leetcode.com/problems/my-calendar-iii/discuss/1456107/C%2B%2B-Dynamic-Segment-Tree-Lazy-Propagation-Solution-O(D)
     int book(int start, int end) {
        return sTree->update(start,end-1);
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
