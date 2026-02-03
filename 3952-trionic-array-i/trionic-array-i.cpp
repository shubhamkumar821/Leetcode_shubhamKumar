class Solution {
public:
    bool isTrionic(vector<int>& arr) {
          int maxima=0;
          int minima=0;
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]){
                maxima++;
            }
              if(arr[i-1]>arr[i] && arr[i]<arr[i+1]){
                minima++;
            }

            if(arr[i]==arr[i-1] || arr[i]==arr[i+1]){
                return false;
            }

        }

        if(maxima==1 && minima==1  && arr[0]<arr[1] && arr[arr.size()-2] <arr[arr.size()-1]){
            return true;
        }
        return false;
        
    }
};