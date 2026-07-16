class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long ans=0;
        vector<int>st;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){

            maxi=max(maxi,nums[i]);

            int val=gcd(maxi,nums[i]);
            st.push_back(val);
        }

        sort(st.begin(),st.end());
        if(n%2==0){
            int l=0;
            int h=n-1;
            while(l<h){
                ans+=gcd(st[l],st[h]);
                h--;
                l++;
            }
        }

        else{
             int l=0;
            int h=n-1;
            while(l<h){
                ans+=gcd(st[l],st[h]);
                h--;
                l++;
            }
        }
        return ans;
        
    }
    int gcd(int a,int b){
        if(b==0){
            return  a;
        }
         return gcd(b,a%b);
    }
};