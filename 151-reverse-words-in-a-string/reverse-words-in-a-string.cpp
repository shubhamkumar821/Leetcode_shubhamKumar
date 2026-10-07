class Solution {
public:
    string reverseWords(string s) {

          string t="";
        int n=s.size();
        int st=0;;
        int end=n-1;
        for(int i=0;i<n;i++){
            if(s[i]==' ')continue;
            else{
                st=i;
                break;
                
            }
        }
        
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ')continue;
            else {
                end=i;
                break;
                
                
            }
        }
        
        for(int i=st;i<=end;i++){
            if(s[i]==' ' && s[i+1]==' '){
                continue;
            }
            else{
                t+=s[i];
            }
            
        }
        int prev=0;
               
           
        
        for(int i=0;i<t.size();i++){
            if(t[i]==' ' ){
                reverse(t.begin()+prev,t.begin()+i);
                prev=i+1;
            }
            else if(i==t.size()-1){
                   reverse(t.begin()+prev,t.end());
                
                
            }
          
            
        }
       
          
        reverse(t.begin(),t.end());
         return t;
        
    }
};