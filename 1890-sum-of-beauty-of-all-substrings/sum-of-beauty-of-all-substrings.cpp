class Solution {
public:
    int beautySum(string s) {
      
       int ans=0;
        for(int i=0;i<s.size();i++){
              map<char,int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                if(mp.size()>1){
                    int x=INT_MAX;
                    int y=INT_MIN;
                    for(auto i:mp){
                        x=min(x,i.second);
                        y=max(y,i.second);
                    }
                    ans+=y-x;

                }
                

            }
        }
        return ans;
        
    }
};