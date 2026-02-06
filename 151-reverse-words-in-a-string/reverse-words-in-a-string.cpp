class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int j=s.size()-1;
        while(s[i]==' '){
            i++;
        }
        
         while(s[j]==' '){
            j--;
        }
        string t=" ";
        bool space=true;
        for(int k=i;k<=j;k++)
        {
            if(s[k]==' ' ){
           if(space){
            t+=' ';
            space=false;

           }
           else {
            continue;
           }
            }
            else{
                t+=s[k];
                space=true;
            }
        }
          int interval=0;
        for(int a=0;a<t.size();a++){
            if(t[a]==' '){
                reverse(t.begin()+interval,t.begin()+a);
                interval=a+1;
            }
        }
        reverse(t.begin()+interval,t.end());
        reverse(t.begin(),t.end());
        t.pop_back();
        
        return t;
        

        

        
    }
};