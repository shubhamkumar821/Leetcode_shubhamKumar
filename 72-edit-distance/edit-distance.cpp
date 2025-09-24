class Solution {
public:
    int minDistance(string word1, string word2) {
        int a = word1.size();
        int b = word2.size();
        vector<vector<int>> dp(a+1, vector<int>(b+1, 0));

        // base cases
        for (int i = 0; i <= a; i++) dp[i][0] = i;
        for (int j = 0; j <= b; j++) dp[0][j] = j;

        // fill dp
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j];  // no cost if same char
                } else {
                    dp[i+1][j+1] = 1 + min({dp[i][j],     // replace
                                            dp[i][j+1],   // delete
                                            dp[i+1][j]}); // insert
                }
            }
        }

        return dp[a][b];
    }
};
