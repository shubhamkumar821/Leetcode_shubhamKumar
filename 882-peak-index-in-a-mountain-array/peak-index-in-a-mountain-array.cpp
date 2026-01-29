class Solution {
public:
vector<int>st;
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int h=arr.size()-1;
        st=arr;
        int ans=-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(check(mid)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;


        
    }
    bool check(int x){
        if(st[x]>st[x+1]){
            return 1;
        }
        return false ;

    }
};