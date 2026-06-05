class Solution {
public:
int n;
vector<int> dp;

    bool wordBreak(string s, vector<string>& wordDict) {
        
        n=wordDict.size();
        dp.assign(s.size(),-1);
        return rec(0,wordDict,s);
    }
    bool rec(int idx, vector<string>& wordDict,string & s){
        if(idx==s.size()){
            return true;
        }
        if(dp[idx]!=-1)return dp[idx];

        for(int i=0;i<n;i++){
            int len=wordDict[i].size();
            if(len+idx<=s.size() && s.substr(idx,len)==wordDict[i]){
                if(rec(idx+len,wordDict,s)){
                    return dp[idx]=1;
                }

            }                    
        }
        return dp[idx]=0;
    }
};