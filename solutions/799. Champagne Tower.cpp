class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int n= query_row;
        vector<double> first(n+1,0),second(n+1,0);
        
        int curr_row = 0;
        first[0] = poured;
        while(curr_row<query_row)
        {
             second[0]=0;
            for(int i=0;i<curr_row+1;++i)
            {
                second[i] += (first[i]>=1)?(first[i]-1)/2 : 0;
                second[i+1] = (first[i]>=1)?(first[i]-1)/2 : 0;
            }
            swap(first,second);
            ++curr_row;
        }
        return first[query_glass]>=1? 1:first[query_glass] ;
    }
};
