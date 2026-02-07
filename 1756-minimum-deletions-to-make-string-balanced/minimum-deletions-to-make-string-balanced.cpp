class Solution {
public:
    int minimumDeletions(string s) {
        int cnt=0;
        int ans=0;
        for(auto i :s){
            if(i=='a'){
                ans++;
            }
            else{
                cnt++;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};