class Solution
{
public:
    vector<vector<int>> memo;
    int minDistance1(string word1, string word2)
    {
        memo.resize(word1.length() + 1, vector<int>(word2.length() + 1, -1));
        return minDistanceRecur(word1, word2, word1.size(), word2.size());
    }
    // official solution : top down
    int minDistanceRecur(string &word1, string &word2, int word1Index, int word2Index)
    {
        if (word1Index == 0) // delete all words
        {
            return word2Index;
        }
        if (word2Index == 0) // insert all words
        {
            return word1Index;
        }
        if (memo[word1Index][word2Index] != -1)
        {
            return memo[word1Index][word2Index];
        }
        int minEditDistance = 0;
        if (word1[word1Index - 1] == word2[word2Index - 1])
        {
            minEditDistance = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
        }
        else
        {
            int insertOperation = minDistanceRecur(word1, word2, word1Index, word2Index - 1);
            int deleteOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index);
            int replaceOperation = minDistanceRecur(word1, word2, word1Index - 1, word2Index - 1);
            minEditDistance = min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
        }
        memo[word1Index][word2Index] = minEditDistance;
        return minEditDistance;
    }
    // bottom up approach
    // https://leetcode.com/problems/edit-distance/discuss/662240/C%2B%2B-Easy-DP-Solution-(Well-Commented-)
    int minDistance(string word1, string word2) {
// Create a table to store results of subproblems
        int dp[word1.size()+1][word2.size()+1];
// If first string is empty, only option is to 
// insert all characters of second string 
        for(int k=0; k<=word1.size(); k++)
            dp[k][0] = k;
// If second string is empty, only option is to 
// remove all characters of first string
        for(int k=0; k<=word2.size(); k++)
            dp[0][k] = k;
// Fill dp[][] in bottom up manner 
        for(int i=1; i<=word1.size(); i++){
            for(int j=1; j<=word2.size(); j++){
//if characters at current position in 2 strings are equal
//there will be no new operation so copy value from previous position
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
// If the last character is different, consider all 
// possibilities and find the minimum
                else
                    dp[i][j] = 1 + min({dp[i][j - 1], // Insert 
                                   dp[i - 1][j], // Remove 
                                   dp[i - 1][j - 1]}); // Replace 
            }
        }
        
        return dp[word1.size()][word2.size()];
    }
};
