class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=*max_element(weights.begin(), weights.end());;
        
        int hi=accumulate(weights.begin(), weights.end(), 0);;
      
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid,weights,days)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
        
    }
    bool check(int mid,vector<int>& arr, int days){
        int days_taken=0;
        int weight_left=0;
        for(int i=0;i<arr.size();i++){
            if(weight_left>=arr[i]){
                weight_left-=arr[i];
            }
            else{
                
                days_taken++;
                  if(days_taken>days){
                    return false;
                }
                weight_left=mid;
                if(weight_left>=arr[i]){
                      weight_left-=arr[i];
                }
                
                else{
                  return false;
            }
        }
        }
        return true;

    }
};