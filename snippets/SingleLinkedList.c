

//SINGLY LINKED LISTS 
// Like arrays, Linked List is a linear data structure. Unlike arrays, linked list elements are not stored at contiguous location; the elements are linked using pointers.
// Why Linked List?
// Arrays can be used to store linear data of similar types, but arrays have following limitations.
// 1) The size of the arrays is fixed: So we must know the upper limit on the number of elements in advance. Also, generally, the allocated memory is equal to the upper limit irrespective of the usage.
// 2) Inserting a new element in an array of elements is expensive, because room has to be created for the new elements and to create room existing elements have to shifted.
// For example, in a system if we maintain a sorted list of IDs in an array id[].
// id[] = [1000, 1010, 1050, 2000, 2040].
// And if we want to insert a new ID 1005, then to maintain the sorted order, we have to move all the elements after 1000 (excluding 1000).
// Deletion is also expensive with arrays until unless some special techniques are used. For example, to delete 1010 in id[], everything after 1010 has to be moved.
// Advantages over arrays
// 1) Dynamic size
// 2) Ease of insertion/deletion
// Drawbacks:
// 1) Random access is not allowed. We have to access elements sequentially starting from the first Node. So we cannot do binary search with linked lists.
// 2) Extra memory space for a pointer is required with each element of the list.
// Representation in C:
// A linked list is represented by a pointer to the first Node of the linked list. The first Node is called head. If the linked list is empty, then value of head is NULL.
// Each Node in a list consists of at least two parts:
// 1) data
// 2) pointer to the next Node
// In C, we can represent a Node using structures. Below is an example of a linked list Node with an integer data.




#include <stdio.h>
#include <stdlib.h>  



struct Node{
	
	int data;
	struct Node* next;
};

//inserts Node to beginning of the list
static void insertNewNode(struct Node** head, int data){

	struct Node *newNode= (struct Node*)malloc(sizeof(struct Node));
	newNode->data= data;
	newNode->next = *head;
	*head = newNode;
}
 //======
/* Function to push a Node */
void push(struct Node** headRef, int data)
{
 struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
 newNode->data= data;
 newNode->next= *headRef;
 *headRef= newNode;
 
}


//adds Node to end of the list
static void appendNewNode(struct Node** headRef, int data){

    struct Node* current = *headRef;
    struct Node* newNode= (struct Node* )malloc(sizeof(struct Node));
    
    newNode->data=data;
    newNode->next=NULL;
	if(current==NULL){
		*headRef= newNode;
	}
	
	else{
		while(current->next!=NULL){
		
			current=current->next;
		}
		current->next=newNode;
	}
	
}

/* Function to reverse the linked list */ 
static void reverse(struct Node** headRef){
	
	struct Node* prev= NULL;
	struct Node* current= *headRef;
	struct Node* next= NULL;
	
	while(current!=NULL){
		
		next=current->next;
		current->next=prev;
		prev= current;
		current= next;
	}
	*headRef=prev;
}  
  
  
/* Given a reference (pointer to pointer) to the head of a list
   and a key, deletes the first occurrence of key in linked list */
void deleteNode(struct Node **headRef, int key){
	
	//if(!*headRef)return;

	struct Node* current;
	struct Node* prev;
	current=*headRef;
	
	//if head contains the keyValue
	if(current->data==key&&current!=NULL){
		*headRef=current->next;
		free(current);
		return;
	}
	
	while(current->data!=key&&current!=NULL){
		
		prev= current;
		current=current->next;
	}
	// key was not present in the list
	if(current==NULL)return; 
	prev->next=current->next;
	free(current);

}  

/* Counts number of nodes in linked list */
//iterative version
    int getCount(struct Node* head){
        int nrOfNodes=0;
        while(head){
            head=head->next;
            nrOfNodes++;
        }
        return nrOfNodes;
    
    }  
    
//recursive version
   int getCountRec(struct Node* head){
        int nrOfNodes=0;
        
        if(!head)
            return 0;
        
        
        return 1+getCountRec(head->next);
    
    }  


/* get Nth element from list, return data at index*/
int getNth(struct Node* head, int index)
{
    struct Node* current = head;
    int count = 0; /* the index of the node we're currently
                  looking at */
    while (current != NULL)
    {
       if (count == index)
          return(current->data);
       count++;
       current = current->next;
    }
   
    return -1 ; //cannot reach here
}   
   
   
 /* Given only a pointer to a node to be deleted in a singly linked list, how do you delete it? */ 
 //Fast solution is to copy the data from the next node to the node to be deleted and delete the next node. Something like following.
 // fails if we want to delete the last node : ) 
 void deleteNode(struct Node *nodePtr)   
{
   struct Node *temp = nodePtr->next;
   nodePtr->data    = temp->data;
   nodePtr->next    = temp->next;
   free(temp);
}    




/* Function to get the middle of the linked list*/
//Traverse linked list using two pointers. Move one pointer by one and other pointer by two. 
//When the fast pointer reaches end slow pointer will reach middle of the linked list.
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}


/* Function to get the middle of the linked list*/
 // Just set mid pointer to point to head, then traverse trhough list, incrementing counter;
 // when count is odd, increment mid pointer
void printMiddle2(struct Node *head)
{
    int count = 0;
    struct Node *mid = head;
 
    while (head != NULL)
    {
        /* update mid, when 'count' is odd number */
        if (count & 1)
            mid = mid->next;
 
        ++count;
        head = head->next;
    }
 
    /* if empty list is provided */
    if (mid != NULL)
        printf("The middle element is [%d]\n\n", mid->data);


    
    
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//prints singly linked list
static void printList(struct Node* Node){
	
	while(Node!=NULL){
		printf("%d, ", Node->data);
		Node= Node->next;
		 
	}
	printf("\r\n");
}

int main() {
	struct Node * head =NULL;
	struct Node* second = NULL;
	struct Node* third = NULL;
	
	   /* reverse list Tests */
	head= (struct Node*)malloc(sizeof(struct Node));
    second= (struct Node*)malloc(sizeof(struct Node));
    third= (struct Node*)malloc(sizeof(struct Node));	
	
	head->data= 1;
	head->next= second;
	
	head->data= 1;
	head->next= second;
	
	second->data= 2;
	second->next= third;
	
	
	third->data= 3;
	third->next= NULL;
	
	printList(head);
	insertNewNode(&head, 0);
	printList(head);
	
	printList(head);
	appendNewNode(&head, 23);
	printList(head);
    
    
    /* reverse list Tests */
    struct Node* head = NULL;
    
    push(&head, 20);
    push(&head, 4);
    push(&head, 15); 
    push(&head, 85);      
      
    printList(head);    
    reverse(&head);                      
    printf("\n Reversed Linked list \n");
    printList(head);    
     
     
    /* delete Node Tests */
    struct Node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 2);
    puts("\nLinked List after Deletion of 1: ");
    printList(head);
    
    
     /* count Nodes Tests */
    struct Node* head = NULL;
 
    /* Use push() to construct below list
     1->2->1->3->1  */
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
 
    /* Check the count function */
    printf("count of nodes is %d", getCount(head));
    printf("count of nodes in Rec way is %d", getCountRec(head));

	return 0;
}