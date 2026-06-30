class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            bool check=false;
            
            if(!st.empty()  && st.top()=='*' && s[i]!='*'){
                st.pop();
                check=true;

            }
            if(check){
                check=false ;
                continue;
            }
            st.push(s[i]);
        }
        string str="";
        while(!st.empty()){
            str+=st.top();
            st.pop();

        }
        return str;
        
    }
};