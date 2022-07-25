#if 0
// segment-tree, 54 / 54 Test case passed but TLE
/// Need to optimize as other segment tree solutions are acceptable
// likely like lazy updates.
struct stree{
    int low,high;
    stree *left,*right;
    bool tracked;
    stree(int rlow,int rhigh){
        low = rlow;
        high = rhigh;
        left = right = nullptr;
        tracked = false;
    }
    void add(int rlow,int rhigh) {
        if(rlow> high || rhigh < low)
            return;
        if(rlow<=low && rhigh>=high){
            tracked = true;
            if(left){
                left->add(rlow,rhigh);
                right->add(rlow,rhigh);
            }
            return;
        }
        if(tracked)
            return;
        int mid = low + (high-low)/2;
        if(!left) {
            left = new stree(low,mid);
            right = new stree(mid+1,high);
        }
        left->add(rlow,rhigh);
        right->add(rlow,rhigh);
        tracked = right->tracked && left->tracked;
        return;
    }
    bool query(int rlow, int rhigh){
        if(rlow> high || rhigh < low)
            return false;
        if((rlow<=low && rhigh>=high) || tracked || !left){
            return tracked;
        }
        int mid = low + (high-low)/2;
        if(mid >= rhigh)
            return left->query(rlow,rhigh);
        else if(mid<rlow)
            return right->query(rlow,rhigh);
        else 
            return left->query(rlow,rhigh) && right->query(rlow,rhigh);
        return false;
    }
    void remove(int rlow,int rhigh){
         if(rlow> high || rhigh < low)
            return;
        int mid = low + (high-low)/2;
        
        if((rlow<=low && rhigh>=high)){
            tracked = false;
            if(left) {
                left->remove(rlow,rhigh);
                right->remove(rlow,rhigh);
            }
            return;
        }
        if(!tracked && !left)
            return;
        if(!left) {
            left = new stree(low,mid);
            right = new stree(mid+1,high);
            left->tracked = tracked;
            right->tracked = tracked;
        }
            
        if(mid >= rhigh)
            left->remove(rlow,rhigh);
        else if(mid<rlow)
            right->remove(rlow,rhigh);
        else {
            left->remove(rlow,rhigh);
            right->remove(rlow,rhigh);
        }
        tracked = false;
    }
};
class RangeModule {
    stree tree;
public:
    RangeModule():tree(1,1e9) {
        
    }
    
    void addRange(int left, int right) {
        tree.add(left,right-1);
        
    }
    
    bool queryRange(int left, int right) {
        return tree.query(left,right-1);
    }
    
    void removeRange(int left, int right) {
        tree.remove(left,right-1);
    }
};

// https://leetcode.com/problems/range-module/discuss/108912/C%2B%2B-vector-O(n)-and-map-O(logn)-compare-two-solutions
// 446 ms
class RangeModule {
public:
    void addRange(int left, int right) {
        auto l = invals.upper_bound(left), r = invals.upper_bound(right); 
        if (l != invals.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l != r) {
            left = min(left, l->first);
            right = max(right, (--r)->second);
            invals.erase(l,++r);
        }
        invals[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = invals.upper_bound(left);
        if (it == invals.begin() || (--it)->second < right) return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = invals.upper_bound(left), r = invals.upper_bound(right); 
        if (l != invals.begin()) {
            l--;
            if (l->second < left) l++;
        }
        if (l == r) return;
        int l1 = min(left, l->first), r1 = max(right, (--r)->second);
        invals.erase(l, ++r);
        if (l1 < left) invals[l1] = left;
        if (r1 > right) invals[right] = r1;
    }
private:
    map<int, int> invals;
};

// another one based on map
//https://leetcode.com/problems/range-module/discuss/475266/C%2B%2B-amortized-O(log(n)
// 385 ms
class RangeModule {
    map<int, int, greater<int>> tree;	// start -> end
public:
    void addRange(int left, int right) {
        for (auto it = tree.lower_bound(right); it != tree.end() && it->second >= left;) {
            left = min(left, it->first);
            right = max(right, it->second);
            it++;
            tree.erase(prev(it));
        }
        tree[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = tree.lower_bound(left);
        if (it == tree.end()) {
            return false;
        }
        return right <= it->second;
    }
    
    void removeRange(int left, int right) {
        for (auto it = tree.upper_bound(right); it != tree.end() && it->second > left;) {
            auto nt = next(it);
            if (it->second > right) {
                tree[right] = it->second;
            }
            if (it->first < left) {
                it->second = left;
            } else {
                tree.erase(it);
            }
            it = nt;
        }
    }
};
#endif
//https://leetcode.com/problems/range-module/discuss/388941/Trust-me-it's-great-Generalizable-Segment-Tree-Solution330msand-140MB
// Check later Segment tree : 533 ms
template <typename T> 
class MemoryPool {
 public:
  std::array<T, 10000000> mem_pool;
  int ptr = 0;
  T *offer() {
    return &mem_pool[ptr++];
  }
};


struct LogicalAndMonoid {
  typedef bool T;
  T append(T a, T b) const { return a && b; }
  T unit() const { return true ;}
};


struct MaskOperatorMonoid {
  typedef bool T;
  typedef int  F;
  F identity() const { return -1; }
  T apply(F a, T b) const {
    if (a == -1) return b;
    return a;
  }
  F compose(F a, F b) const {
    return a;
  }
};


template <typename M, typename O>
class Node {
 public:

  typedef typename M::T T;
  typedef typename O::F F;
  static constexpr M mon {};
  static constexpr O op {}; 
  static Node *build(int, int, T  = mon.unit(), F = op.identity(), Node<M, O>* = nullptr, Node<M, O>* = nullptr);
  
 public:
  int ll, rr;
  T val; 
  F f;
  
  Node* lch; 
  Node* rch;

  void push() {
    if (lch != nullptr || rch != nullptr)
      return;
    // hard coded predicate to terminate push
    if (ll +1 == rr)
      return;
    grow();
    lch->f    = op.compose(f, lch->f);
    rch->f   = op.compose(f, rch->f);
    f = op.identity();
    lch->val  = op.apply(lch->f, lch->val);
    rch->val = op.apply(rch->f, rch->val);
  }
  void retract() {
    if (lch != nullptr)  lch->retract();
    if (rch != nullptr) rch->retract();
    lch = nullptr;
    rch = nullptr;
  }
  void grow() {
    if (lch == nullptr)  lch  = build(ll, (ll + rr) / 2);
    if (rch == nullptr) rch = build((ll + rr) / 2, rr);
  }
};

MemoryPool<Node<LogicalAndMonoid, MaskOperatorMonoid>> mem_pool;


template <typename M, typename O>
Node<M, O>* Node<M, O>::build(int ll, int rr, T init_t, F init_f, Node<M, O>* lch, Node<M, O>* rch) {  
  Node * ret  =  mem_pool.offer();
  ret->ll  = ll;
  ret->rr    = rr;
  ret->val    = init_t;
  ret->f      = init_f;
  ret->lch   = lch;
  ret->rch  = rch;
  return ret;
}


template <typename M, typename O>
class LazyDynamicSegmentTree {
 public:

  using T = typename Node<M, O>::T;
  using F = typename Node<M, O>::F;
  
  static constexpr M mon = Node<M, O>::mon;
  static constexpr O op  = Node<M, O>::op;
  
  Node<M, O> *root; 

  LazyDynamicSegmentTree() {
    root = Node<M, O>::build(0, 1000000000, false, false);
  }
     
  
  void range_apply(int a, int b, bool v) {
    range_apply(root, a,  b, v);
  }
  
  
  void range_apply(Node<M, O> * node, int a, int b, bool v) {
    if(a >= node->rr || b <= node->ll) {
      return;
    }
    Node<M, O> * &lch  = node->lch;
    Node<M, O> * &rch = node->rch;
    if(a <= node->ll && b >= node->rr) {
      node->val = op.apply(v, node->val);
      node->f   = op.compose(v, node->f);
      node->retract();
      return;
    }      
    node->push();   
    range_apply(lch, a, b, v);
    range_apply(rch, a, b, v);
    node->val = op.apply(node->f, mon.append(lch->val, rch->val));
  }  

  
  bool range_concat(int a, int b) {  
    return range_concat(root, a, b);
  }

  
  bool range_concat(Node<M, O> * node, int a, int b) {
    if(a >= node->rr || b <= node->ll) {
      return mon.unit();
    }          
    if(a <= node->ll && b >= node->rr) {
      return node->val;
    }
    if(node->lch == nullptr) {
      return node->val;
    }
    // alternatively, one could do this.
    // node->push();
    return op.apply(node->f, mon.append(range_concat(node->lch, a, b), range_concat(node->rch, a, b)));
  }
};

  

class RangeModule {
 public:
  LazyDynamicSegmentTree<LogicalAndMonoid, MaskOperatorMonoid> h;
  
  RangeModule() : h() {
  }  
    
  void addRange(int left, int right) {
    h.range_apply(left, right, true);
  }
    
  bool queryRange(int left, int right) {
    return h.range_concat(left, right);
  }
    
  void removeRange(int left, int right) {
    h.range_apply(left, right, false);
  }
  
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
