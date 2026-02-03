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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
if(lists.empty()){
        return nullptr;
    }
    while(lists.size() > 1){
        lists.push_back(merge(lists[0], lists[1]));
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists.front();
    
        
    }
    ListNode* merge(ListNode*l1,ListNode*l2){
        ListNode*ptr=new ListNode(0);
        ListNode*curr=ptr;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val>=l2->val){
                curr->next=l2;
                l2=l2->next;
            }
            else{
                curr->next=l1;
                l1=l1->next;
            }
            curr=curr->next;

        }

        if(l1!=nullptr){
            curr->next=l1;

        }
        if(l2!=nullptr){
            curr->next=l2;

        }
        return ptr->next;



    }
};