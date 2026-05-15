class Solution {
public:
    int nthUglyNumber(int n) {

        vector<int>ugly(n,0);
        int p2=0;
        int p3=0;
        int p5=0;
        ugly[0]=1;

        for(int i=1;i<n;i++){
            int a=ugly[p2]*2;
            int b=ugly[p3]*3;
            int c=ugly[p5]*5;
            ugly[i]=min({a,b,c});

            if(ugly[i]==a)p2++;
            if(ugly[i]==b)p3++;
            if(ugly[i]==c)p5++;
        }

        return ugly[n-1];
        
    }
};