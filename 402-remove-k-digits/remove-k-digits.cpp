class Solution {
public:
    string removeKdigits(string num, int k) {


        stack<char>st;

        for(int i=0;i<num.size();i++){
            if(st.empty())
            {
                st.push(num[i]);
            }
            else {
                while(!st.empty() && k>0 && (num[i]<st.top())){
                    st.pop();
                    k--;

                }
                  st.push(num[i]);

            }
          

        }
        string s="";

        while(!st.empty() && k>0){
            st.pop();
            k--;

        }
        if(st.empty())return "0";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }

        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0')s.pop_back();
            else break;
        }
        if(s.size()==0)return "0";
        

        reverse(s.begin(),s.end());
        return s;
        
    }
};