//Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//12ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* pointer = &head;
        while(l1!=NULL && l2 !=NULL)
        {
            int v1 = l1->val;
            int v2 = l2->val;
            if(v1 < v2)
            {
                pointer->next = l1;
                ListNode* tmp = l1;
                while(v1<v2)
                {
                    tmp = l1;
                    l1 = l1->next;
                    if(l1 != NULL)
                    {
                        v1 = l1->val;
                    }
                    else
                    {
                        break;
                    }
                }
                pointer = tmp;
            }
            else
            {
                pointer->next = l2;
                ListNode* tmp = l2;
                while(v1>=v2)
                {
                   
                    tmp = l2;
                    l2 = l2->next;
                    if(l2 != NULL)
                    {
                        v2 = l2->val;
                    }
                    else
                    {
                        break;
                    }
                }
                pointer = tmp;
            }
        }
        pointer->next = (l1==NULL)?l2:l1;
        return head.next;
    }
};
 //12ms
class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode head(0);
        ListNode* tp = &head;
        while(l1!=NULL && l2 !=NULL){
            int t1 = l1->val;
            int t2 = l2->val;
            if(t1<t2){
                ListNode* tmp = l1->next;
                tp->next = l1;
                l1 = tmp;
            }
            else{
                ListNode* tmp = l2->next;
                tp->next = l2;
                l2 = tmp;
            }
            tp = tp->next;
        }
        if(l1==NULL){tp->next = l2;}
        else{tp->next = l1;}
        return head.next;        
    }
};

/* vector实现*/
vector<int> mergeArrays(vector<int>& a, vector<int>& b) {
	vector<int> result;
	result.reserve(a.size() + b.size());
	vector<int>::iterator la, lb;
	la = a.begin();
	lb = b.begin();
	while (la != a.end() && lb != b.end())
	{
		int v1 = *la;
		int v2 = *lb;
		if (v1 < v2)
		{
			result.push_back(v1);
			la++;
		}
		else
		{
			result.push_back(v2);
			lb++;
		}
	}
	while (la != a.end())
	{
		result.push_back(*la);
		la++;
	}
	while (lb != b.end())
	{
		result.push_back(*lb);
		lb++;
	}
	return result;
}