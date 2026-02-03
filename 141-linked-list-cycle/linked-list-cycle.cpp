/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        map<ListNode*,int>mp;
        while(head){
            mp[head]++;
            head=head->next;
            if(mp[head]>0){
                return true;
            }
        }
        return false;
    }
};