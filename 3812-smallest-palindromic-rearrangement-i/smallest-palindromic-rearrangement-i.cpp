class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26);
        for(auto i:s){
            int a=i-'a';
            freq[a]++;
        }
        string l="",r="",m="";
        for(int i=0;i<26;i++){
            for(int j=0;j<freq[i]/2;j++){
                l+=char(i+'a');
            }
       if(freq[i]%2==1)m+=char(i+'a');
            
        }

        r=l;
        reverse(r.begin(),r.end());

        return l+m+r;

        
        
    


        
    }
};