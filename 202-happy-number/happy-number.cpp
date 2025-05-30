class Solution {
public:
    bool isHappy(int n) {
        map<int ,int>mp;
        int t=n;
        while(n!=1){

            int sum=0;
            while(t!=0){
          int k=t%10;
            sum+=pow(k,2);
            t/=10;
            }
            t=sum;
            n=sum;
        mp[sum]++;
        if(mp[sum]>1){
            return false;
        }
        

        }
        return true;
        
    }
};
