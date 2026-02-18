class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s="";
        while(n){
            if(n&1){
                s+='1';
            }
            else{
                s+='0';
            }
            n=n>>1;
        }


        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){
                return false;
            }
            else{
                continue;
            }
        }
        return true;        
    }
};