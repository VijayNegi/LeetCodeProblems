class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size();
        int win=0;
        int winner=arr[0];
        for(int i=1;i<n;++i){
            if(arr[i]>winner){
                winner = arr[i];
                win = 1;
            }
            else ++win;
​
            if(win==k)
                return winner;
        }
        return winner;
    }
};
