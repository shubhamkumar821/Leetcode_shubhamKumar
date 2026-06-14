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
int ans;
    int pairSum(ListNode* head) {
        ListNode*right=head;
        ListNode*left=head;
        if(head==nullptr)return 0;
        rec(right,left);
        return ans;
        
    }
    void rec(ListNode*&right,ListNode*&left){

        if(right->next!=nullptr){
            rec(right->next,left);
        }
        ans=max(ans,right->val+left->val);
        left=left->next;

    }
};