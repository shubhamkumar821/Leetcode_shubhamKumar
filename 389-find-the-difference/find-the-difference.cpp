class Solution {
public:

    char findTheDifference(string s, string t) {
        sort(s.begin(),s.end());
    int x=0;
    for(auto i:s){
        x^=i;
    }
    for(auto i:t){
        x^=i;
    }
    return (char)x;
        
    }
};