/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *      struct Data;
 *      Data* data;
 *  public:
 *      Iterator(const vector<int>& nums);
 *      Iterator(const Iterator& iter);
 *
 *      // Returns the next element in the iteration.
 *      int next();
 *
 *      // Returns true if the iteration has more elements.
 *      bool hasNext() const;
 *  };
 */
​
class PeekingIterator : public Iterator {
   int val{-1};
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        if(Iterator::hasNext())
            val = Iterator::next();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return val;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int temp = val;
        val =-1;
        if(Iterator::hasNext())
            val = Iterator::next();
        return temp;
    }
    
    bool hasNext() const {
        if(val == -1)
            return false;
        return true;
    }
};
