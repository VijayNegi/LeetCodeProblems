class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ans=0;
        
        while(target>startValue)
        {
            ++ans;
            if(target%2==1)
                ++target;
            else
                target >>= 1;
        }
        return ans + startValue-target;
    }
    //https://leetcode.com/problems/broken-calculator/discuss/234484/JavaC%2B%2BPython-Change-Y-to-X-in-1-Line
    // startvalue to target
    int brokenCalc1(int X, int Y) {
        int multiple = 1, res = 0;
        while (X * multiple < Y)
            multiple <<= 1, res++;
        int diff = X * multiple - Y;
        while (diff > 0) {  
            res += diff / multiple;
            diff -= diff / multiple * multiple;
            multiple >>= 1;
        }
        return res;
    }
};
