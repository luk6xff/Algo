//https://www.hackerrank.com/challenges/ctci-linked-list-cycle
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head)
{
    if(head == NULL)
    {
        return false;
    }
    Node* slowPtr = head;
    Node* fastPtr = head->next;
    
    while(slowPtr != NULL && fastPtr != NULL && fastPtr->next !=NULL )
    {
        if(slowPtr == fastPtr)
        {
            return true;
        }
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    
    return false;
}

