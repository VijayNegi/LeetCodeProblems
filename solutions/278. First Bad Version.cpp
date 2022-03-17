// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
​
class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        int bad =0;
        int mid;
        while(end>=start){
            mid = start+ (end-start+1)/2; // avoid overflow
            if(isBadVersion(mid)){
                bad = mid;
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return bad;
    }
};
