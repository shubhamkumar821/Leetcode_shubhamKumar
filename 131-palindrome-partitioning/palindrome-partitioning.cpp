class Solution {
public:
 vector<vector<string>>ans;
    vector<vector<string>> partition(string s) {

        vector<string>st;
        backtrack(0,s,st);
        return ans;
       

       
        
    }

    void backtrack(int start,string s,vector<string>&st){

        if(start==s.size()){
            ans.push_back(st);
            return;

        }

        for(int end=start;end<s.size();end++){
            if(palindrome(s,start,end )){
                st.push_back(s.substr(start,end-start+1));
                


                backtrack(end+1,s,st);


                st.pop_back();
            }
        }

    }
    bool palindrome(string &s ,int st,int end){
        if(st>=end)return 1;

        return s[st]==s[end]&& palindrome(s,st+1,end-1);
    }
};