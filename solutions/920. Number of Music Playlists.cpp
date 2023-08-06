const int mod = 1e9+7;
class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        vector dp(goal+1, vector<long>(n+1,-1));
        function<long(int,int)> playlistCount = [&](int toPlay,int uniquePlayed) -> long {
            // base cases
            if(toPlay == 0 && uniquePlayed == 0 )
                return 1;
            if(toPlay == 0 || uniquePlayed == 0 )
                return 0;
            if(dp[toPlay][uniquePlayed] != -1)
                return dp[toPlay][uniquePlayed];
            
            // play a new song
            dp[toPlay][uniquePlayed] = (playlistCount(toPlay-1, uniquePlayed-1) * (n- uniquePlayed + 1)) % mod;
            // replay a old song
            if(uniquePlayed > k){
                dp[toPlay][uniquePlayed] += (playlistCount(toPlay-1,uniquePlayed) * (uniquePlayed-k)) % mod;
                dp[toPlay][uniquePlayed] %= mod;
            }
            return dp[toPlay][uniquePlayed];
        };
        return playlistCount(goal,n);
    }
};
​
​
