class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
       int i=0;
       long long sum=0;

        while(n)
       {
        int k=n%10;
        if(k==0){
            n=n/10;
            continue;

        }
        sum+=k;
        ans=ans+k*pow(10,i);
        i++;
        n=n/10;
        
       } 

       return ans*sum;
    }
};