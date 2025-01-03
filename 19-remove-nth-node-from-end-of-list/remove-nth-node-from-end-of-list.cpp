/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head){
            return head;
        }
         ListNode*prev=nullptr;
        ListNode*cur=head;
        for(int i=0;i<n;i++){
            cur=cur->next;

        }
        if(!cur){
            return head->next;
        }
        while(cur){
            cur=cur->next;
            if(prev)prev=prev->next;
            else prev=head;
        }

        prev->next=prev->next->next;
        return head;
       
    
        
        
    }
};