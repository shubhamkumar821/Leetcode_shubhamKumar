class Solution {
public:
    int minimumPushes(string word) {
        map<char,int>freq;
        for(auto i:word){
            freq[i]++;
        }

 vector<pair<char, int>> v(freq.begin(), freq.end());

    sort(v.begin(), v.end(), [](pair<char, int> &a, pair<char, int> &b) {
        return a.second > b.second;   // Descending frequency
    });
    int cnt=0;
  int ans=0;
    for(auto i:v){
    if(cnt<8){
       ans+=i.second;
       cnt++;
    }
    else if(cnt>=8 && cnt<16){
        ans+=2*i.second;
        cnt++;

    }else if(cnt>=16 && cnt<24){
        ans+=3*i.second;
        cnt++;

    }
    else{
          ans+=4*i.second;

    }
    }
    return  ans;
        
    }
};