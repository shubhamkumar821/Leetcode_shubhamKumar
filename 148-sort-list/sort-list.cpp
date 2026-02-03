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
    ListNode* sortList(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
          if(head == NULL || head ->next == NULL)
            return head;
        while(fast->next!=nullptr && fast!=nullptr){
                fast=fast->next;
                if(fast->next!=nullptr){
                    fast=fast->next;
                    slow=slow->next;
                }
        }
    ListNode*temp=slow->next;
    slow->next=nullptr;
        ListNode*l1=sortList(temp);
        ListNode*l2=sortList(head);
        return mergeList(l1,l2);
        
    }
    ListNode*mergeList(ListNode*l1,ListNode*l2){
        ListNode*ptr=new ListNode(0);
        ListNode*curr=ptr;

        while(l1!=nullptr && l2!=nullptr){
            if(l1->val>=l2->val){
                 curr->next=l2;
                 l2=l2->next;

            }
            else{
                 curr->next=l1;
                 l1=l1->next;
                
            }
    curr = curr ->next;

        }

         if(l1 != NULL)
        {
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL)
        {
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }


    
};