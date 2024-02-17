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

// https://leetcode.com/problems/building-h2o/discuss/1184961/C%2B%2B-solution-with-posix-semaphores-and-barriers
#include<semaphore.h>
class H2O {
public:
    pthread_barrier_t b;
    sem_t h;
    sem_t o;
    H2O() {
        pthread_barrier_init(&b, 0, 3); //Need 3 threads to pass the barrier
        sem_init(&h, 0, 2); // Two molecules of hydrogen
        sem_init(&o, 0, 1); // One molecule of oxygen
    }

    void hydrogen(function<void()> releaseHydrogen) {
        
        sem_wait(&h); // Two hydrogen threads can arrive at a time
        pthread_barrier_wait(&b); // but wait for one more thread , which must be oxygen
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        sem_post(&h);
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o);  // only one oxygen can arrive
        pthread_barrier_wait(&b); // but wait for 3 threads at this barrier, 2 of twhich must be hydrogen
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        sem_post(&o);
    }
};
