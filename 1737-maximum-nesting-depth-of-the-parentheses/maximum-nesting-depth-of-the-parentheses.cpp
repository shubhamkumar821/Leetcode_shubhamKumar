class Solution {
public:
    int maxDepth(string s) {

        int ans=INT_MIN;
        int cnt=0;
        for(auto i:s){
            if(i=='('){
                cnt++;
            }

            else if(i==')'){
                cnt--;
            }

            ans=max(ans,cnt);
        }
        return ans;
        
    }
};