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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return  head;
        }
        ListNode*temp=nullptr;
        rev(head,temp);
        return temp;

        
    }
    
    void rev(ListNode* temp, ListNode* &Head1) {
        if (temp->next == nullptr) {
            Head1 = temp;
            return;
        }

        rev(temp->next, Head1);
        temp->next->next = temp;
        temp->next = nullptr;
    }
};