class Solution {
public:
    int minLength(string s) {
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(!st.empty() && ((st.top()=='A' && s[i]=='B') || (st.top()=='C'  && s[i]=='D'))){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        return st.size();
        
    }
};