/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space?
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* tp = head;
        ListNode* tq = head;
        int stp = 0;
        while(tp!= NULL&&tq!=NULL){
            if(tp->next!=NULL){tp = tp->next;}
            else{return NULL;}
            if(tq->next!=NULL){
                tq = tq->next;
                if(tq->next!=NULL){tq = tq->next;}
                else{return NULL;}
            }
            else{return NULL;}
            stp++;
            if(tp==tq){break;}
        }
        tp = head;
        while(tp!=tq){
            tp = tp->next;
            tq = tq->next;
        }
        return tp;
    }
};