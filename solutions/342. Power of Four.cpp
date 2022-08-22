class Solution {
public:
    bool isPowerOfFour1(int n) {
        long m=1;
        while(m<INT_MAX) {
            if(n==m)
                return true;
            m*=4;
        }
        return false;
    }
    bool isPowerOfFour2(int num) {
        while(num > 1) {
            if(num % 4)return false;
            num /= 4;
        }
        return num == 1;
    }
    bool isPowerOfFour3(int num) {
        if(num<0)return false;
        for(int i=0;i<32;i+=2)if(num==1<<i)return true;
        return false;
    }
    bool isPowerOfFour4(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
    //it's easy to find that power of 4 numbers have those 3 common features.
    // First,greater than 0.
    // Second,only have one '1' bit in their binary notation,so we use x&(x-1) to delete the lowest '1',and if then it becomes 0,it prove that there is only one '1' bit.
    // Third,the only '1' bit should be locate at the odd location,for example,16.It's binary is 00010000.So we can use '0x55555555' to check if the '1' bit is in the right place.With this thought we can code it out easily!
    bool isPowerOfFour(int num) {
        return num > 0 && (num&(num-1)) == 0 && (num & 0x55555555) != 0;
    }
};
