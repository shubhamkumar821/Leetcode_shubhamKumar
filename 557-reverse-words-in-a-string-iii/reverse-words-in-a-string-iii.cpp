class Solution {
public:
    string reverseWords(string s) {
            string t="";
            string x="";
        for(auto u:s){

            if(u!=' '){
                t+=u;

            }
            else {
                reverse(t.begin(),t.end());
                x+=t;
                t="";
                x+=' ';

            }
            
            
        }
        reverse(t.begin(),t.end());
        x+=t;
        return x;

        
    }
};