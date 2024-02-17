/* self
class H2O {
    std::mutex mu;
    int hCount{0};
    int oCount{0};
    std::condition_variable cond1,cond2;
public:
    H2O() {
        
    }
    void reset(){
        if(hCount==2 && oCount==1){
            hCount=oCount=0;
        }
    }
​
    void hydrogen(function<void()> releaseHydrogen) {
        
        std::unique_lock<mutex> locker(mu);
        cond1.wait(locker,[&](){if(hCount<2) return true; return false;});
        ++hCount;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        reset();
        locker.unlock();
        cond2.notify_one();
        cond1.notify_one();
    }
​
    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<mutex> locker(mu);
        cond2.wait(locker,[&](){if(oCount<1) return true;return false;});
        ++oCount;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        reset();
        locker.unlock();
        cond1.notify_one();
    }
};
*/
​
// https://leetcode.com/problems/building-h2o/discuss/1184961/C%2B%2B-solution-with-posix-semaphores-and-barriers
#include<semaphore.h>
