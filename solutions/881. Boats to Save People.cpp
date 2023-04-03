class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int result=0;
        int l=0,r=people.size()-1;
        sort(begin(people),end(people));
        while(l<=r){
            if(people[l]+people[r]<= limit)
                ++l,--r;
            else
                --r;
             ++result;
        }
        return result;
    }
};
