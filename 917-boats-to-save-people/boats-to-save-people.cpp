class Solution {
public:
    int numRescueBoats(vector<int>& arr, int limit) {
        int i=0;
        int j=arr.size()-1;
        int pr=0;
        int n=arr.size();

        sort(arr.begin(),arr.end());
        while(i<j){
            if(arr[i]+arr[j]<=limit){
                i++;
                j--;
                pr++;
            }

          else{
            j--;
          }

        }
        int ans=n-pr;
        return ans;

        
    }
};