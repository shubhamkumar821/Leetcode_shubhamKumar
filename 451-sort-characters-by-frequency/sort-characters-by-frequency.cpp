class Solution {
public:
    string frequencySort(string s) {

        map<char,int> mpp;

        for(auto i : s) {
            mpp[i]++;
        }

        priority_queue<pair<int,char>> pq;

        for(auto i : mpp) {
            pq.push({i.second, i.first});
        }

        string st = "";

        while(!pq.empty()) {

            auto x = pq.top();
            pq.pop();

            for(int i = 0; i < x.first; i++) {
                st += x.second;
            }
        }

        return st;
    }
};