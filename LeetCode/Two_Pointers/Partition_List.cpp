/*
86
*/
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* large=new ListNode(0);
        ListNode* less=new ListNode(0);
        ListNode* temp1=large;
        ListNode* temp2=less;
        while(head){
            if(head->val>=x){
                large->next=head;
                large=large->next;
            }
            else{
                less->next=head;
                less=less->next;
            }
            head=head->next;
        }
        less->next=temp1->next;
        large->next=nullptr;
        
        return temp2->next;
    }
};