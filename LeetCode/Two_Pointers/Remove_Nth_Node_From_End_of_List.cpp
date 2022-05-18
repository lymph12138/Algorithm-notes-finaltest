/*
19
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left=head;
        ListNode* right=head;
        for(int i=0;i<n;i++)
            right=right->next;
        if(!right)  return head->next;
        ListNode* temp;
        while(right){
            temp=left;
            left=left->next;
            right=right->next;
        }
        temp->next=left->next;
        return head;
    }
};