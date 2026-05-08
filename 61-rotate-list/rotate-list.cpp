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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr  || head->next==nullptr || k==0 )return head;
      int len=0;
      ListNode*temp=head;
      while(temp){
        len++;
        temp=temp->next;
      }
      ListNode*h=head;
      temp=head;
      k=k%len;
      if(k==0)return head;
      int x=len-k;
      while(head->next){
        head=head->next;
      }
      ListNode*ans=temp;
      for(int i=0;i<x-1;i++){
        temp=temp->next;
        ans=ans->next;

      }
      ans=ans->next;
      temp->next=nullptr;
      head->next=h;
       
      return ans;

        
    }
};