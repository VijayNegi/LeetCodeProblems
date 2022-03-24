class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(begin(people),end(people));
        
        int l=0,r=people.size()-1;
        int ans = 0;
        while(l<=r)
        {
            ++ans;
            if(people[l]+people[r]<= limit) // if lightest person can be adjusted with heavy person then do so.
                ++l;
            --r; // move heaviest persion
        }
        return ans;
    }
};
