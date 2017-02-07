/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(head==NULL){return NULL;}
        ListNode* p = head->next,*q = head;
        while(p!=NULL)
        {
            if(p->val == val)
            {
                p = p->next;
                delete q->next;
                q ->next = p;
            }
            else
            {
                p = p->next;
                q = q->next;
            }
        }
        if(head->val==val){return head->next;}
        else{return head;}
    }
};