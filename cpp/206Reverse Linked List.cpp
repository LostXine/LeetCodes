/*
Reverse a singly linked list.

click to show more hints.

Hint:
A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        else{
            ListNode* tmp = head->next;
            if(tmp==NULL){return head;}
            ListNode* result =  reverseList(tmp);
            tmp->next = head;
            head->next = NULL;
            return result;
        }
    }
};