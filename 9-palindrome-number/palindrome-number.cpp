class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        string s=to_string(x);
        string t=s;
    reverse(s.begin(),s.end());
    if(s==t){
        return  true;
    }
    return false;
        
    }
};