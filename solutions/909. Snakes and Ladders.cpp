class Solution {
public:
    // self: 7 ms
    int snakesAndLadders1(vector<vector<int>>& board) {
        int n = board.size();
        int k = n-2;
        while(k >=0){
            reverse(board[k].begin(),board[k].end());
            k -=2;
        }
        vector<int> dp(n*n+1,INT_MAX);
        dp[0] = 1;
        unordered_set<int> s{0};
        int range = n*n;
        int step=0;
        while(s.size()){
            unordered_set<int> next;
            for(auto k:s){
                int last = min(range,k+7);
                for(int i=k+1;i<last;++i){
                    //if(dp[i]<=step) continue;
                    int r = n-1 -i/n;
                    int c = i%n;
                    int dist = board[r][c] != -1 ? board[r][c]-1 : i;
                    if(dist==range-1) return step+1;
                    if(dp[dist] == INT_MAX){
                        dp[dist] = step;
                        next.insert(dist);
                    
                    }
                }    
            }
            swap(s,next);
            ++step;
        }
        return -1;
    }
    // OFFICIAL: 46 ms
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[label++] = {row, column};
            }
