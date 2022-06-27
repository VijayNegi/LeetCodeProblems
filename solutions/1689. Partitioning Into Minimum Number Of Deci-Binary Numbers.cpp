class Solution {
public:
    int minPartitions(string n) {
        int count=0;
        for(auto& c:n) {
            count = max(count,c-'0');
        }
        return count;
    }
};
