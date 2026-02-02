class Solution {
public:
    int countPrimes(int n) {
        if(n<=1){
            return 0;
        }
        int cnt=0;
        vector<bool>check(n,true);
        check[0]=check[1]=false;
        for(int i=2;i*i<n;i++){
           if(check[i]){
            for(int j=i*i;j<n;j+=i){
                check[j]=false;
            }
           }
        }
        for(auto i:check){
            if(i)cnt++;
        }
        return cnt;
    }
 
};