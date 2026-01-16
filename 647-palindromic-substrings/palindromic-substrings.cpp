#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001]; // -1 = unknown, 0 = false, 1 = true

    bool isPalindrome(int i, int j, string &s) {
        if (i >= j) return true;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = isPalindrome(i + 1, j - 1, s);
        }
        return dp[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.size();
        memset(dp, -1, sizeof(dp));

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(i, j, s)) {
                    res++;
                }
            }
        }
        return res;
    }
};
