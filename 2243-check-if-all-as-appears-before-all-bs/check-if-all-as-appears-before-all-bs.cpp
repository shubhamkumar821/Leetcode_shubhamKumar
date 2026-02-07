class Solution {
public:
    bool checkString(string s) {
        int j=s.size()-1;
        int i=0;
        int cnta=0;
        int cntb=0;
        int n=s.size();
        while(i<n && s[i]=='a'){
            i++;
            cnta++;
        }
          while(j>=0 && s[j]=='b'){
            cntb++;
            j--;
        }
        if(cnta+cntb==s.size()){
            return true;
        }
        return false;
    }
};