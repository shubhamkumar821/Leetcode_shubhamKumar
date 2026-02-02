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
    ListNode* deleteMiddle(ListNode* head) {
    ListNode*slow,*fast;
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    slow=head;
    fast=head;
    while(fast->next!=nullptr){
        fast=fast->next;
        if(fast->next!=nullptr && fast->next->next!=nullptr ){
            fast=fast->next;
            slow=slow->next;
        }
    }
    ListNode*temp=slow->next;
slow->next=slow->next->next;
delete temp;
   // slow->next->next=nullptr;
    return head;
        
    }
};