class Solution {
public:
    string firstPalindrome(vector<string>& words) {
          string t="";
        for(auto i:words){
            string s=i;
            reverse(s.begin(),s.end());
        if(s==i){
            return i;
        }
        }
        return t;
        
    }
};