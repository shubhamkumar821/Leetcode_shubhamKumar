class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Edge case
        if (head == nullptr) return head;

        // Step 1: Find length
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        // If head needs to be deleted
        if (n == len) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // Step 2: Reach node before the one to delete
        int del = len - n - 1;
        temp = head;
        while (del--) {
            temp = temp->next;
        }

        // Step 3: Delete node
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};
