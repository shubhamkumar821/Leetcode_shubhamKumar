class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string t = "";
        if (strs.size() == 0) return t;

        string s = strs[0];
        int m = s.size();

        for (int i = 0; i < m; i++) {
            if (check(s[i], strs, i)) {
                t += s[i];
            } else {
                break;
            }
        }
        return t;
    }

    bool check(char ch, vector<string>& s, int k) {
        for (int i = 0; i < s.size(); i++) {
            if (k >= s[i].size() || s[i][k] != ch) {
                return false;
            }
        }
        return true;
    }
};
