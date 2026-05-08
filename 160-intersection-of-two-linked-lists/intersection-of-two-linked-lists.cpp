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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr || headB==nullptr){
            return nullptr;
        }
        int A=0,B=0;
        ListNode*tempA=headA;
         ListNode*tempB=headB;
        while(headA){
            A++;
            headA=headA->next;
        }
          while(headB){
            B++;
            headB=headB->next;
        }
        if(A>B){
            int x=A-B;

            headA=tempA;
            headB=tempB;
            for(int i=0;i<x;i++){
               headA= headA->next;
            }
             while(headA && headB){
            if(headA==headB){
                return headA;
                
            }
            headA=headA->next;
            headB=headB->next;

        }
            

        }
        else{
            int x=B-A;
        headB=tempB;
        headA=tempA;
        for(int i=0;i<x;i++){
            headB=headB->next;
        }
        while(headA && headB){
            if(headA==headB){
                return headA;
                
            }
            headA=headA->next;
            headB=headB->next;

        }

        }
        return nullptr;
        
    }
};