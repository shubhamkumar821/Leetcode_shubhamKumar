class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {
         
    vector<int>incom(n+1,0),outgo(n+1,0);
   
    for(auto t: trust)
    {
        incom[t[1]]++;
        outgo[t[0]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(incom[i]==n-1&&outgo[i]==0)
        {
            return i;
        }
    }
    return -1;
    }
};