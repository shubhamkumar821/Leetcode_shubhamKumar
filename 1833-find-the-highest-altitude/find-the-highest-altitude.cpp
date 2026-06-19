class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int n=gain.size();
        vector<int>pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=gain[i]+pref[i];
        }
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            if(pref[i+1]>=pref[i] && pref[i+1]>=pref[i+2]) ans=max(ans, pref[i+1]);
        }

        if(0>=pref[1])ans=max(ans,0);
        if(pref[n]>=0)ans=max(ans,pref[n]);
        if(ans==INT_MIN)return 0;
        return ans;
        
    }
};