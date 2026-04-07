class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;

        ListNode* temp = head;

        while(head && head->next) {
            if(head->val == head->next->val) {
                head->next = head->next->next; // delete duplicate
            } else {
                head = head->next; // move only when no deletion
            }
        }

        return temp;
    }
};