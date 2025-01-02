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
        if(!head)
        return head;
        if(!k){
            return head;
        }
        
        ListNode*cur=head;
        ListNode*res=head;
        int cnt=0;
        while(cur){
            cnt++;
            res=cur;
            cur=cur->next;
        }
        k=k%cnt;
        cur=head;
        for(int i=0;i<cnt-1-k;i++){
            cur=cur->next;
        }
        res->next=head;
        ListNode*temp=cur->next;
        cur->next=nullptr;
        return temp;

        
    }
};