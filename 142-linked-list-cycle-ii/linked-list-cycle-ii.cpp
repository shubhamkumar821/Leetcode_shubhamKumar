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
        if(head==nullptr || head->next==nullptr){
            return nullptr;
        }
         map<ListNode*,int>mp;
        while(head){
            mp[head]++;
            head=head->next;
            if(mp[head]>0){
                return head;
            }
        }
        return head;
        
    }
};