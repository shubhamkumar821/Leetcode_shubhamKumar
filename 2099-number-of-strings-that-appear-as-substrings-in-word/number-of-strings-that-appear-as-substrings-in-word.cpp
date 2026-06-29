class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int cnt = 0;

        for (string i : patterns) {

            int k = i.size();
            int n = word.size();

            if (k > n)
                continue;

            for (int j = 0; j <= n - k; j++) {

                string s = word.substr(j, k);

                if (s == i) {
                    cnt++;
                    break;          // Count each pattern only once
                }
            }
        }

        return cnt;
    }
};