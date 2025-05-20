class Solution {
public:
bool check(string s,string t){
    for(int i=0;i<s.size();i++){
        if(s[i]!=t[i])
        return false ;
    }
    return true;
}
    bool isAnagram(string s, string t) {    sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        int n=s.size();
        int m=t.size();
        if(m!=n){
            return false;
        }
        else{
return check(s,t);
        }
        
    }
};