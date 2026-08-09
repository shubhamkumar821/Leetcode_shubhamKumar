class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int head=0;
        int tail=0;
        int discnt=0;
        map<int,int>mp;
        int n=fruits.size();
        int ans=0;

        while(tail<n){
            while(head<n  && (discnt<2 ||( discnt==2 && mp[fruits[head]]>0))){
                if(mp[fruits[head]]==0){
                    discnt++;

                }
                mp[fruits[head]]++;
                head++;
            }
            ans=max(ans,head-tail);
            if(mp[fruits[tail]]==1){
                discnt--;
            }
            mp[fruits[tail]]--;
            tail++;
        }
        return ans;
        
    }
};