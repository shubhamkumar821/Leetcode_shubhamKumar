class Solution {
public:
    double myPow(double x, int n) {
        long long N=n;
        if(n<0){
            N=-N;
            x=1/x;
        }
        return solve(x,N);
        
    }
    double solve(double x, int n){
        if(n==0){
            return 1;
        }
      double y=  solve(x,n/2);
      if(n%2==0){
        return y*y;
      }
      else{
    return y*y*x;
      }

    }
};