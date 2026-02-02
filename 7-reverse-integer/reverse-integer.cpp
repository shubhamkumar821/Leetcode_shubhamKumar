class Solution {
public:
    int reverse(int x) {
        if(x<0){
              long reverse = 0;
        int xcopy = x;
       
        if(x<=INT_MIN){
            return 0;
        }
         x=-x;

        while (x > 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }
        
        if(reverse>=INT_MAX){
            return 0;
        }
        int ans=reverse;
        return -ans; 
        }
        

        
        else{
            long reverse = 0;
        int xcopy = x;

        while (x > 0) {
            reverse = (reverse * 10) + (x % 10);
            x /= 10;
        }
         if(reverse>INT_MAX){
            return 0;
        }
        int ans=reverse;
        return ans; 
        }
        
    }
};