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
        ListNode*slow=head;
        ListNode*fast=head;
        if(head==nullptr && head->next==nullptr)return nullptr;
        while(fast && fast->next){
            fast=fast->next;
            if(fast->next==nullptr || fast->next->next==nullptr)break;
            slow=slow->next;
            fast=fast->next;

        }
        if(slow->next==nullptr)return nullptr;
        slow->next=slow->next->next;
        slow=slow->next;
        slow=nullptr;
        return head;
        
    }
};