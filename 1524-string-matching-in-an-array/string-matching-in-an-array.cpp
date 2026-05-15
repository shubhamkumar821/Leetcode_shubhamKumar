class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;

        int n = words.size();

        for (int i = 0; i < n; i++) {
            string a = words[i];

            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                string b = words[j];

                if (a.size() > b.size()) continue;

                for (int k = 0; k <= b.size() - a.size(); k++) {

                    string c = b.substr(k, a.size());

                    if (c == a) {
                        ans.push_back(a);
                        break;
                    }
                }

                // stop checking once found
                if (!ans.empty() && ans.back() == a)
                    break;
            }
        }

        return ans;
    }
};