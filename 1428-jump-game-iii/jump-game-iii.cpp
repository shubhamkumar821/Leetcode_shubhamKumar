class Solution {
public:
  int n;
      vector<int> vis;
    bool canReach(vector<int>& arr, int start) {
        int maxi=INT_MIN;
        n=arr.size();
       
        vis.assign(n,0);
        return rec(start,arr);

        
    }

    bool rec(int i,vector<int>& arr){
    
        if(i<0 || i>=n){
            return false;
        }
            if(arr[i]==0){
            return true;
        }
        if(vis[i]){
            return false;
        }
        vis[i]=1;
        
        

        bool check=rec(i+arr[i],arr)||rec(i-arr[i],arr);
        return check;
    }
};