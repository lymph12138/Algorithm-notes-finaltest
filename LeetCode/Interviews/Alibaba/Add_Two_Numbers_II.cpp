/*
445
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
    string add(vector<int>& num1,vector<int>& num2){
        int m=num1.size();
        int tag=0;
        string ans="";
        for(int i=0;i<m;i++){
            int temp=num1[m-1-i]+num2[m-1-i]+tag;
            tag=temp/10;
            char c=temp%10+'0';
            ans=c+ans;
        }
        if(tag) ans='1'+ans;
        return ans;
    }
    void view(ListNode* l, vector<int>& num){
        if(!l)  return;
        num.push_back(l->val);
        view(l->next,num);
    }
    void res(ListNode* &l,int idx,string sum){
        if(idx==sum.size()) return;
        ListNode* temp=new ListNode(sum[idx]-'0');
        l->next=temp;
        res(temp,idx+1,sum);
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> num1,num2;
        view(l1,num1);
        view(l2,num2);
        if(num1.size()<num2.size()) num1.insert(num1.begin(),num2.size()-num1.size(),0);
        if(num2.size()<num1.size()) num2.insert(num2.begin(),num1.size()-num2.size(),0);
        string sum=add(num1,num2);
        ListNode* l=new ListNode(sum[0]-'0');
        res(l,1,sum);
        return l;
    }
};