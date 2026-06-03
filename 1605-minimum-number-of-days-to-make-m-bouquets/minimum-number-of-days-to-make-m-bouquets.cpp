class Solution {
public:
int K,M,n;
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=1;
        int h=-1e9;
        K=k;
        M=m;
        for(int i:bloomDay){
            h=max(h,i);
        }

         n=bloomDay.size();
        long long total=1LL*m*k;
        if(n<total)
        {
            return -1;
        }
        int ans=h;

        while(l<=h){
            long long mid=(l+h)/2;

            if(check(mid,bloomDay)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }


        }
        return ans;
        
    }

    bool check(int x,vector<int>&arr){
       int flower=0;
       int  bq=0;


        for(int i=0;i<n;i++){
            if(arr[i]<=x){
                flower++;
                 if(flower==K){
                bq++;
                flower=0;
            }
            }
           
            
        else{
            flower=0;
        }


        }

        return bq>=M;


    }


};