class Solution {
public:
    int dp[110][110];

    bool checkValidString(string s) {
        memset(dp, -1, sizeof(dp));
        return check(0, 0, s);
    }

    bool check(int i, int open, string &s) {
        if (open < 0) return false;          // IMPORTANT
        if (i == s.size()) return open == 0;

        if (dp[i][open] != -1)
            return dp[i][open];

        bool result;
        if (s[i] == '(') {
            result = check(i+1, open+1, s);
        }
        else if (s[i] == ')') {
            result = check(i+1, open-1, s);   // FIXED
        }
        else { // '*'
            result = check(i+1, open+1, s) ||
                     check(i+1, open-1, s) ||
                     check(i+1, open, s);
        }

        return dp[i][open] = result;
    }
};
