class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int i = 0;
        int l = n - 1;

        while(i < l) {
            if(s[i] == s[l]) {
                char ch = s[i];

                while(i <= l && s[i] == ch)
                    i++;

                while(i <= l && s[l] == ch)
                    l--;
            }
            else {
                break;
            }
        }

        if(i > l)
            return 0;

        return l - i + 1;
    }
};