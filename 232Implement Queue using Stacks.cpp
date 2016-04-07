/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
*/

class Queue {
private:
struct node{
    node* next;
    int val;
    node(int x):val(x),next(NULL){}
};

public:
    node* head;
    node* tail;
    
    Queue(){
        head = NULL;
        tail = NULL;
    }
    // Push element x to the back of queue.
    void push(int x) {
        node* tmp = new node(x);
        if(empty()){
            head = tmp;
        }
        else
        {
            tail->next = tmp;
        }
        tail = tmp;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        node* tmp = head->next;
        delete head;
        head = tmp;
    }

    // Get the front element.
    int peek(void) {
        return head->val;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return head==NULL;
    }
};