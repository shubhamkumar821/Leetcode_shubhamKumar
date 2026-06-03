class Solution {
public:
    int findPeakElement(vector<int>& arr) {

        int l=0;
        int r=arr.size()-1;
        int n=arr.size();
        if(arr.size()==1)return 0;
        if(arr[0]>arr[1])return 0;
        if(arr[n-1]>arr[n-2]) return n-1;
        
        int ans=-1;
        while(l<=r){
            long long mid=(l+r)/2;
            if(arr[mid]>arr[mid+1] && arr[mid-1]<arr[mid]){
                ans=-1;
                return mid;
            }

            else if(arr[mid+1]>arr[mid] ){
                l=mid+1;
            }

          else if(arr[mid]<arr[mid-1]){
            r=mid-1;
          }
        }

    return 0;
        
    }
};