class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1;
        int sum=0;
        while(n>0){
            int k=n%10;
            prod*=k;
            sum+=k;
            n=n/10;
        }
        return (prod-sum);
    }
};