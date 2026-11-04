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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL){
            return head;
        }
        ListNode *p=head;
        ListNode *q=head->next;
        ListNode *r=NULL;
        while(p->next != NULL){
            if(p->val == p->next->val){
                //ListNode* temp = p->next;
                p->next = p->next->next;
            }else{
                p = p->next;
            }
        }
        return head;
    }
};