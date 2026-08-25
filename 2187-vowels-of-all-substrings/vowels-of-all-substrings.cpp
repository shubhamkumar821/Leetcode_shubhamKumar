class Solution {
public:
    long long countVowels(string word) {
        int n=word.length();
        long long ans=0;
        
        for(int i=0;i<n;i++){
            if(word[i]=='a'  ||word[i]=='e'|| word[i]=='o'|| word[i]=='u'||word[i]=='i'){
             ans+=1LL*(i+1)*1LL*(n-i);
            }
        }
        return ans;


        
        
    }
};