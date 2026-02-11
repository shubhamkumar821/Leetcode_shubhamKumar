class Solution {
public:
    double myPow(double x, int n) {
        long long k=n;
        return powf(x,k);
        
    }
    double powf(double x,long long  n){
        if(n==0)return 1;
        if(n<0) return powf(1/x,-n);
        if(n%2==0) return powf(x*x,n/2);
        return pow(x*x,(n-1)/2)*x;
    }
};