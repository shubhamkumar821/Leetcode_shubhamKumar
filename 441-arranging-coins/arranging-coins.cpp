class Solution {
public:
    int arrangeCoins(int n) {
        long long a=0;
        if(n==1){
            return 1;

        }
        for(int i=1;i<=n;i++){
         a+=i;
            if(n-a<0){
                return i-1;
            }
        }
        return 0;
        
    }
};