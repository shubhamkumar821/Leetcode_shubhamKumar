class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;

        for(int i=0;i<=rowIndex;i++){
            int  val=nCr(rowIndex,i);
            ans.push_back(val);

        }
        return ans;
    }
    int nCr(int n,int r){
    long long res=1;
    for(int i=0;i<r;i++){
        res=res*(n-i);
        res=res/(i+1);
    }
    return (int)(res);
}
    
};