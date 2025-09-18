class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         string s=strs[0];
         int ans=INT_MAX;

        for(auto i: strs){
            ans=min(func(s,i),ans);

        }
        string t="";
        for(int i=0;i<ans;i++){
            t+=s[i];
        }
        return t;
        
    }
    int func(string s,string t){
        int cnt=0;
        for(int i=0;i<min(s.size(),t.size());i++){
            if(s[i]==t[i]){
                cnt++;

            }
            else{
                break;

            }
        }

        return cnt;
    }
};