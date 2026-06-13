class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

map<char,int>mpp;
int j=0;
for(char i='a';i<='z';i++){
    int a=weights[i-'a'];
    mpp[i]=a;
}
string s="";
for(auto i:words){
    int sum=0;
    for(auto v: i){
        sum+=mpp[v];

    }
    sum%=26;
    s+='z'-sum;
    
    
}
return s;

        
    }
};