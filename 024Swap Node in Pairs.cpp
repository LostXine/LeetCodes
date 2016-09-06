24. Swap Nodes in Pairs  QuestionEditorial Solution  My Submissions
Total Accepted: 118201
Total Submissions: 325046
Difficulty: Easy
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

Subscribe to see which companies asked this question

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



    ListNode* swapPairs(ListNode* head) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        else if(head -> next == NULL)
        {
            return head;
        }
        else
        {
            ListNode* tail = swapPairs(head->next->next);
            ListNode* sec = head->next;
            sec->next = head;
            head->next = tail;
            return sec;
        }
    }
};