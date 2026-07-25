class Solution {
public:
    int n, m;
    string str1, str2;
    vector<vector<int>> dp;

    bool isMatch(string s, string p) {
        str1 = s;
        str2 = p;
        n = s.size();
        m = p.size();

        dp.assign(n + 1, vector<int>(m + 1, -1));

        return rec(0, 0);
    }

    bool rec(int i, int j) {

        if (i == n && j == m)
            return true;

        if (j == m)
            return false;

        if (i == n) {
            while (j < m && str2[j] == '*')
                j++;
            return j == m;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        if (str1[i] == str2[j] || str2[j] == '?') {
            ans = rec(i + 1, j + 1);
        }
        else if (str2[j] == '*') {
            ans = rec(i + 1, j) || rec(i, j + 1);
        }

        return dp[i][j] = ans;
    }
};