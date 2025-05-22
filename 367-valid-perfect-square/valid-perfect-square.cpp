class Solution {
public:
    bool isPerfectSquare(int num) {


        int l=1;
        int h=num;
        long long ans=1;
        while(l<=h){
            long long mid=l+(h-l)/2;
            if(check(mid,num)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
    if(ans*ans==num){
        return true;
    }
    else {
        return false;
    }
        
    }
    bool check(long long x,int num){
        if(x*x>=num){
            return true;
        }
        else{
            return false;
        }
    }
};