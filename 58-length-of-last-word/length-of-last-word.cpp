class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int cnt=0;
        bool ans=false;
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                cnt++;
                ans=true;
            }
            else if(ans){
               break;
            }
        }
        return cnt;
        
    }
};