class Solution {
public:
    int strStr(string haystack, string needle) {

        string s = needle + "#" + haystack;

        int n = s.size();
        int m = needle.size();

        vector<int> lps(n + 1);

        lps[0] = -1;

        int i = 0, j = -1;

        while (i < n) {
            while (j != -1 && s[i] != s[j])
                j = lps[j];

            i++;
            j++;
            lps[i] = j;
        }

        for (int i = m + 1; i <= n; i++) {
            if (lps[i] == m)
                return i - 2 * m - 1;
        }

        return -1;
    }
};