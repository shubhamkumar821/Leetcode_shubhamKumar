class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {

        string s="";
        string t="";
        for(auto i:word1){
            for(auto v:i){
                s+=v;
            }
        }

        for(auto i:word2){
            for(auto v:i){
                t+=v;
            }
        }

        return s==t;
        
    }
};