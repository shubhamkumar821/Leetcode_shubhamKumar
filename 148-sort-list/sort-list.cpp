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
    ListNode* sortList(ListNode* head) {
        if(!head){
            return head;
        }
        vector<int>ans;
        while(head){
            ans.push_back(head->val);
            head=head->next;
        }
        sort(ans.begin(),ans.end());
        ListNode*temp=new ListNode(ans[0]);
        ListNode*move=temp;
        for(int i=1;i<ans.size();i++){
            ListNode*store=new ListNode(ans[i]);
            move->next=store;
            move=store;
        }
        return temp;
        
    }
};