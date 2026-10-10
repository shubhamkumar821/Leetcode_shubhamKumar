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
    ListNode *detectCycle(ListNode *head) {

        map<ListNode*,int>mp;
        int cnt=0;

        while(head ){
            if(mp[head]==1){
                return head;
            }
            mp[head]++;
            head=head->next;
        
        }
        return head;
        
    }
};