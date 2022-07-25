  T apply(F a, T b) const {
    if (a == -1) return b;
    return a;
  }
  F compose(F a, F b) const {
    return a;
  }
};
​
​
template <typename M, typename O>
class Node {
 public:
​
  typedef typename M::T T;
  typedef typename O::F F;
  static constexpr M mon {};
  static constexpr O op {}; 
  static Node *build(int, int, T  = mon.unit(), F = op.identity(), Node<M, O>* = nullptr, Node<M, O>* = nullptr);
  
 public:
  int ll, rr;
  T val; 
  F f;
  
  Node* lch; 
  Node* rch;
​
  void push() {
    if (lch != nullptr || rch != nullptr)
      return;
    // hard coded predicate to terminate push
    if (ll +1 == rr)
      return;
    grow();
    lch->f    = op.compose(f, lch->f);
    rch->f   = op.compose(f, rch->f);
    f = op.identity();
    lch->val  = op.apply(lch->f, lch->val);
    rch->val = op.apply(rch->f, rch->val);
  }
  void retract() {
    if (lch != nullptr)  lch->retract();
    if (rch != nullptr) rch->retract();
    lch = nullptr;
    rch = nullptr;
  }
  void grow() {
    if (lch == nullptr)  lch  = build(ll, (ll + rr) / 2);
    if (rch == nullptr) rch = build((ll + rr) / 2, rr);
  }
};
​
MemoryPool<Node<LogicalAndMonoid, MaskOperatorMonoid>> mem_pool;
​
​
template <typename M, typename O>
Node<M, O>* Node<M, O>::build(int ll, int rr, T init_t, F init_f, Node<M, O>* lch, Node<M, O>* rch) {  
  Node * ret  =  mem_pool.offer();
  ret->ll  = ll;
  ret->rr    = rr;
