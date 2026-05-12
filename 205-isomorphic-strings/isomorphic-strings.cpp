class Solution {
public:
    bool isIsomorphic(string s, string t) {

map<char,char>mp,mp2;
    for(int i=0;i<s.size();i++){
        if(!mp[s[i]]){
            mp[s[i]]=t[i];

        }
    if(mp[s[i]]!=t[i]){
        return false;
    }

    }

    for(int i=0;i<s.size();i++){
        if(!mp2[t[i]]){
            mp2[t[i]]=s[i];

        }
    if(mp2[t[i]]!=s[i]){
        return false;
    }

    }
    return true;
       
        
    }
};