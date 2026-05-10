class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        map<string,int>mpp;
        for(auto i:wordList){
            mpp[i]++;
        }

        queue<pair<string,int>>q;

        q.push({beginWord,1});
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            string word=x.first;
            int step=x.second;


            if(word==endWord){
                return step;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char j='a';j<='z';j++){
                    word[i]=j;
                    if(mpp.find(word)!=mpp.end()){
                        mpp.erase(word);
                        q.push({word,step+1});
                    }
                }
                word[i] = original;

            }

        }
        return 0;
        
    }
};