class Solution {
public:
    string largestOddNumber(string num) {
        int ind=-1;
        for(int i=num.size();i>=0;i--){
            int x=num[i]-'1';
            x=x+1;
            if(x%2!=0){
                ind=i;
                break;
            }
        }
         string s="";

        if(ind==-1){
            return s;
        }
  
        for(int i=0;i<=ind;i++){
            s+=num[i];
        }
        return s;
        
    }
};