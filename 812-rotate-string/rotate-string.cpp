class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size())return false;
        goal=goal+goal;
        

        for(int i=0;i<goal.size()-s.size();i++){
            string st=goal.substr(i,s.size());
            if(st==s){
                return true;
            }
        }
        return false;
        
    }
};