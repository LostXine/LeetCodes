2. Add Two Numbers  QuestionEditorial Solution  My Submissions
Total Accepted: 173759
Total Submissions: 702251
Difficulty: Medium
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void tail(ListNode* & p,ListNode* & node,int & add)
{
    while(p!=NULL)
    {
        int val = p->val + add;
        add = val/10;
        val = val%10;
        
        p->val = val;
        node->next = p;
        p = p->next;
        node = node->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == NULL){return l2;}
        if(l2 == NULL){return l1;}
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        ListNode* head = new ListNode(0),*node = head;
        int add = 0;
        while(p1!=NULL && p2!=NULL)
        {
            int val = p1->val+p2->val +add;
            add = val/10;
            val = val%10;
            
            ListNode *pVal = new ListNode(val);
            node->next = pVal;
            node = pVal;
            
            p1 = p1->next;
            p2 = p2->next;
        }
        
        tail(p1,node,add);
        tail(p2,node,add);
        
        if(p1==NULL && p2==NULL && add!=0)
        {
            node->next = new ListNode(add);
        }
        node = head->next;
        delete head;
        return node;
        
    }
};