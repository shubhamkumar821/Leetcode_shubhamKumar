class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        	int n=s.size();
	int tail=0;
	int head=-1;
	map<char,int> freq;
	int ans=0;
	
	while(tail<n){
	    while(head+1<n && (freq[s[head+1]]==0)){
	        head++;
	        freq[s[head]]++;
	    }
	    ans=max(ans,head-tail+1);
	    
	   if(tail<=head){
	       freq[s[tail]]--;
	       tail++;
	       
	   } 
	   else {
	       tail++;
	       head=tail-1;
	       
	   }
	    
	}
    return ans;
        
    }
};