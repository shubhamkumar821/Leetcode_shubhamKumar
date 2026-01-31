class Solution {
public:
vector<string>ans;
int x;
    vector<string> generateParenthesis(int n) {
        x=n;
        rec(0,0,0,"");
        return ans;
        
    }
    void  rec(int i,int open,int close,string s){
        if(i==2*x){
           ans.push_back(s);
            return;
        }

        if(open<x){
            rec(i+1,open+1,close,s+'(');

        }

        if(close<open){
            rec(i+1,open,close+1,s+')');
        }
    }
};