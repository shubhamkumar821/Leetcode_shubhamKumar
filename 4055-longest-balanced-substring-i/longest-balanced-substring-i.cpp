class Solution {
public:
    int longestBalanced(string s) {
      
        int ans=0;

        for(int i=0;i<s.size();i++){
              map<char,int>mpp;
            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;
                char ch=s[i];
                if(check(mpp, ch)){
                    ans=max((int)mpp.size()*mpp[ch],ans);
                }
                
                
            }

        }
        return ans;
        
    }
    bool check(map<char,int>&mpp,char ch){
        int val=mpp[ch];
        for(auto i:mpp){
            if(i.second-val!=0){
                return false;
            }
        }
        return true;
    }
};