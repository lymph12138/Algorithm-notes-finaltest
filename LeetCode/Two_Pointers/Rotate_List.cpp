/*
61
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0)    return head;
        if(!head)   return nullptr;
        int n=0;
        ListNode* temp=head;
        while(temp){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0 || n==1)    return head;
        ListNode* start;
        ListNode* s;
        temp=head;
        for(int i=1;i<=n;i++){
            if(i==n-k){
                s=head;
            }
            if(i==n-k+1)    start=head;
            if(i==n)    head->next=temp;
            head=head->next;
        }
        s->next=NULL;
        return start;
    }
};