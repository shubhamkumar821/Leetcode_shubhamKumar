class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.size())
            return s;

        map<int, vector<char>> mp;

        int i = 0;

        while (i < s.size()) {

            // Going downward
            for (int j = 0; j < numRows && i < s.size(); j++) {
                mp[j].push_back(s[i]);
                i++;
            }

            // Going upward diagonally
            for (int k = numRows - 2; k > 0 && i < s.size(); k--) {
                mp[k].push_back(s[i]);
                i++;
            }
        }

        string t = "";

        for (auto p : mp) {
            for (auto c : p.second) {
                t += c;
            }
        }

        return t;
    }
};