class Solution {
public:

    long long solve(string &word, int k) {

        int n = word.size();

        map<char, int> vowel;
        vowel['a'] = 1;
        vowel['e'] = 1;
        vowel['i'] = 1;
        vowel['o'] = 1;
        vowel['u'] = 1;

        map<char, int> cnt;

        int distinct = 0;
        int consonants = 0;

        int j = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            while (j < n &&
                   (consonants < k || distinct < 5)) {

                if (vowel[word[j]]) {

                    if (cnt[word[j]] == 0)
                        distinct++;

                    cnt[word[j]]++;
                }
                else {
                    consonants++;
                }

                j++;
            }

            // If window [i, j-1] contains
            // all vowels and at least k consonants,
            // then every extension is also valid.
            if (distinct == 5 && consonants >= k) {
                ans += n - j + 1;
            }

            // Remove word[i]
            if (vowel[word[i]]) {

                cnt[word[i]]--;

                if (cnt[word[i]] == 0)
                    distinct--;
            }
            else {
                consonants--;
            }
        }

        return ans;
    }

    long long countOfSubstrings(string word, int k) {

        return solve(word, k) - solve(word, k + 1);
    }
};