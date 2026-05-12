class Solution {
public:
string t;
    string longestPalindrome(string s) {
        t=s;
        string st="";
        pair<int,int>ans;
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(palindrome(i,j)){
                    int x=j-i+1;
                    if(maxi<=x){
                        ans={i,j};
                        maxi=x;

                    }

                }
            }
        }

        for(int i=ans.first;i<=ans.second;i++){
            st+=s[i];
        }
        return st;

        
        
    }

    bool palindrome(int i,int j){
        while(i<=j){
            if(t[i]!=t[j]){
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
};