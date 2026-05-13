class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnta=0,cntb=0,cntc=0;
        int head=0;
        int ans=0;
        int n=s.size();
        for(int tail=0;tail<n;tail++){
            while(head<n && (cnta==0 || cntb==0 || cntc==0)){
                if(s[head]=='a'){
                    cnta++;
                }
                else if(s[head]=='b'){
                    cntb++;
                }
                else{
                    cntc++;
                }
                head++;
            }

             if(cnta > 0 && cntb > 0 && cntc > 0) {
                ans += (n - head + 1);
            }
            if(s[tail]=='a'){
                cnta--;
            }
            else if(s[tail]=='b'){
                cntb--;
            }
            else{
                cntc--;
            }
        }
        return ans;
        
    }
};