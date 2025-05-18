class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>store;
        int opcnt=0;
        int clcnt=0;
        string ans="";
        func(n,store,opcnt,clcnt,ans);
        return store;
        
    }
    void func(int n,vector<string>&store,int opcnt,int clcnt,string ans){
        if(ans.size()==2*n){
            store.push_back(ans);
            return;
        }
        if(opcnt<n){
            func(n,store,opcnt+1,clcnt,ans+'(');
        }
        if(clcnt<opcnt){
              func(n,store,opcnt,clcnt+1,ans+')');
        }

        }
    
};