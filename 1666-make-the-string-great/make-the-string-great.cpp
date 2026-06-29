class Solution {
public:
    string makeGood(string s) {

        stack<char> st;

        for(char i : s)
        {
            if(!st.empty() && abs(st.top() - i) == 32)
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }

        string ans = "";

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};