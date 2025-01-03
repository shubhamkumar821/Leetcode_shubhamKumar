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
    ListNode* middleNode(ListNode* head) {
        if(head->next==NULL){
            return head;
        }
        ListNode*fast=head->next;
        while(1){
            head=head->next;
            fast=fast->next;
            if(fast==NULL || fast->next==NULL){
            break;
            }
            fast=fast->next;
        }
        return head;
    }
};