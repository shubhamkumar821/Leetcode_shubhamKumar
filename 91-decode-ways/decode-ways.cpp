class Solution {
public:
    int n;
    int numDecodings(string s) {
        n=s.size();
        map<int,int>mp;
        mp[n]=1;

       return  rec(0,s,mp);
        
    }
    int rec(int i,string  &s,map<int,int>&mp){
        if(mp.count(i)){
            return mp[i];
        }
        if(s[i]=='0'){
            return 0;
        }
        int ans=rec(i+1,s,mp);
        if(i+1<s.size()){
            if(s[i]=='1' || (s[i]=='2'&& s[i+1]<'7')){
                ans+=rec(i+2,s,mp);

            }
        }
        return mp[i]=ans;

    }
};