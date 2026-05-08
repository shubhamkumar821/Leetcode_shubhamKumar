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
    bool isPalindrome(ListNode* head) {
        if(head==nullptr){
            return true;
        }
        ListNode*temp=head;
        ListNode*f=head;
        
        while(head->next && head->next->next){
            f=f->next;
            head=head->next->next;

        }
        f=f->next;
        ListNode*s=nullptr;
        rev(f,s);
        while(s){
            if(s->val!=temp->val){
                return false;
            }
            s=s->next;
            temp=temp->next;
        }
        return true;
        
        
        
    }

    void rev(ListNode*head,ListNode*&temp){
        if(head==nullptr)return ;
        if(head->next==nullptr){
            temp=head;
            return ;
            
        }
        rev(head->next,temp);

        head->next->next=head;
        head->next=nullptr;



    }
};