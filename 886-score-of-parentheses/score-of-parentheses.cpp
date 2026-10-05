class Solution {
public:
    int scoreOfParentheses(string s) {

      int n=s.size();
      int cnt=0;
      bool br=true;
      int ans=0;

        for(int i=0;i<n;i++){

            if(s[i]=='('){
                cnt++;
            br=true;
            }

            else{
                if(br){
                    ans+=(1<<cnt-1);
                }
                br=false;
                cnt--;
            }
        }
        return ans;


   
        
    }
};