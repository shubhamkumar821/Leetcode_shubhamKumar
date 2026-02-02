class Solution {
public:
    bool isUgly(int n) {
        if(n==1){
            return true;
        }
        if(n<=0){
            return false ;
        }

        return func(n);
        
    }
    bool func(int x){
        if(x==1){
            return true;
        }
        if(x%2==0){
            return func(x/2);
        }
          else if(x%3==0){
            return func(x/3);
        }
        else  if(x%5==0){
            return func(x/5);
        }
        
            return false;
        
    }
};