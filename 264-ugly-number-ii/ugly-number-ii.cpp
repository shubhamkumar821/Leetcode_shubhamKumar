class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>st(n,0);
        int i2=0,i3=0,i5=0;
        st[0]=1;

        for(int i=1;i<n;i++){
            int nextugly=min({st[i2]*2,st[i3]*3,st[i5]*5});
            st[i]=nextugly;
           
            if(nextugly==st[i2]*2)i2++;
             if(nextugly==st[i3]*3)i3++;
              if(nextugly==st[i5]*5)i5++;
        }
        return st[n-1];
    }
};