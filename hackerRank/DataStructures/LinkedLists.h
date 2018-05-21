/********************************************/

/**Print the elements of a linked list*******/

/********************************************/
/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void Print(Node *head)
{
  
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }
}









/********************************************/

/**Insert a node at the tail of a linked list*******/

/********************************************/
/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  Node* newNode= new Node();
  newNode->data=data;
  newNode ->next =NULL;
  if(head==NULL){
      head=newNode;
      return head;
  }
  Node * temp = head;
  while(temp->next!=NULL){
     temp=temp->next;
  }
  temp->next=newNode;
  return head;
}











/********************************************/

/**Insert a node at the head of a linked list*******/

/********************************************/
/*
  Insert Node at the begining of a linked list
  Initially head pointer argument could be NULL for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
return back the pointer to the head of the linked list in the below method.
*/
Node* Insert(Node *head,int data)
{
    Node * newNode = new Node();
    newNode->data=data;
    
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
        return head;
    }
    newNode->next=head;
    head=newNode;
    return head;
}




/********************************************/

/**Insert a node at a specific position in a linked list*******/

/********************************************/
/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
    int counter=1;
    Node* temp =head;
    Node* newNode= new Node();
    newNode->data=data;
    if(temp==NULL){
       newNode->next=NULL;
       head=newNode;
       return head;
    }
    if(position==0){
        newNode->next=temp;
        head=newNode;
        return head;
    }
    while(temp!=NULL){
                
        if(counter==position){          
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
        counter++;
    }
    return head;
}







/********************************************/

/**Delete a Node*******/

/********************************************/
/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
    int count=0; 
    if(head==NULL)
        return head;
    Node* temp =head;
    Node* prev =NULL;
    while(temp!=NULL&&(count++<position)){
        prev=temp;
        temp=temp->next;
    }
    if(position==0){
        head=head->next;
        delete temp;
        return head;
    }
    if(temp==NULL) return head;
    prev->next=temp->next;
    delete temp;
    return head;
  
}








/********************************************/

/**Print in Reverse*******/

/********************************************/
/*
  Print elements of a linked list in reverse order as standard output
  head pointer could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void ReversePrint(Node *head)
{
  if(head!=NULL)
     ReversePrint(head->next);
  else return;
  std::cout<<head->data<<endl;
}





/********************************************/

/**Reverse a linked list*******/

/********************************************/
/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
    // This is a "method-only" submission. 
    // You only need to complete this method. 
Node Reverse(Node head) {
    
    if(head==null)
        return head;
    Node current =head;
    Node next =null;
    Node prev =null;
    while(current!=null){
        
        next = current.next;
        current.next=prev;
        prev= current;
        current= next;
    }
    head= prev;
    return head;

}













/********************************************/

/**Compare two linked lists*******/

/********************************************/
/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
int CompareLists(Node headA, Node headB) {
    
    if(headA==null||headB==null)
        return 0;
    while(headA!=null&&headB!=null&&(headA.data==headB.data)){
        headA=headA.next;
        headB=headB.next;
        if(headA==null&&headB==null){
            return 1;
        }
    }
    return 0;
  
}







/********************************************/

/**Get Node Value*******/

/********************************************/
/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int GetNode(Node *head,int positionFromTail)
{
  Node* next =head->next;
  Node* prev= NULL;
  Node *current =head;
  int position =0;
  while(current!=NULL){     
      next= current->next;
      current->next=prev;
      prev=current;
      current=next;
  }
  head=prev;
  current =head;
  while(current!=NULL){ 
      if(position==positionFromTail){
         break;
      }
      current= current->next;    
      position++;
  }
  return current->data;
}








/********************************************/

/**Delete duplicate-value nodes from a sorted linked list*******/

/********************************************/
/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  Node*current=head;
  Node* prev=NULL;
  
    while(current!=NULL){
        
        if(prev!=NULL){
            if(prev->data==current->data){
                prev->next=current->next;
                Node* temp =current;
                delete temp;
                current=prev->next;
                continue;
            }
        }
        
        prev=current;
        current=current->next;
    }
   return head;
}



/********************************************/

/**Merge two sorted linked lists*******/

/********************************************/
/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* MergeLists(Node *headA, Node* headB)
{
  Node* result =NULL;
  if(headA==NULL){
      return headB;
  }
  if(headB==NULL){
      return headA;
  }
    
  if(headA->data<=headB->data ){
      result=headA;
      result->next= MergeLists(headA->next, headB);
  }
  else{
      result=headB;
      result->next= MergeLists(headA, headB->next);
  }
    
  return result;
}


/********************************************/

/**Detect Cycle*******/

/********************************************/
/*
  Detect loop in a linked list 
  List could be empty also
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
/*Floyd’s Cycle-Finding Algorithm:*/
int HasCycle(Node* head)
{
   Node* fastP =head;
   Node* slowP =head;
   while(fastP!=NULL&&slowP!=NULL&&fastP->next!=NULL){
      
      slowP=slowP->next; 
      fastP=fastP->next->next; 
      if(slowP==fastP)
          return 1;

   }
    
   return 0;
}



/********************************************/

/**Find Merge Point of Two Lists*******/

/********************************************/
/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
//not very efficient
int FindMergeNode(Node *headA, Node *headB)
{
    Node* startB =headB;
    Node* temp =startB;
    while(headA!=NULL){
        
        temp =startB;
        while(temp!=NULL){
            if(temp==headA)
                return temp->data;
            temp=temp->next;
        }
        headA=headA->next;
    }
    return -1;
}




/********************************************/

/**Insert a node into a sorted doubly linked list*******/

/********************************************/
/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
   Node* current = head;
   Node* prev = NULL;
   Node * newNode = new Node();
   newNode->data= data; 
   if(current==NULL){
       head=newNode;
       head->next=NULL;
       head->prev=NULL;
       return head;
   }
   while(current!=NULL){
       
       if(current->data>=newNode->data){
            Node* temp=current->prev;
    
		    if(temp==NULL){
		    	newNode->next=current;
		    	newNode->prev= temp;
		    	current->prev = newNode;
		    	head=newNode;
		    }
		    else if(temp){
		        temp->next=newNode;
				newNode->next=current;
		    	newNode->prev= temp;
		    	current->prev = newNode;
		    }  
           return head;
       }
       prev=current;
       current=current->next;
   } 
   
   newNode->prev=prev;
   newNode->next=NULL;
   current=newNode;
   prev->next=current;
   return head;
}




/********************************************/

/**Reverse a doubly linked list*******/

/********************************************/
Node* Reverse(Node* head)
{
    Node*current=head;
    Node*temp=NULL;
    Node*prev=NULL;
    while(current!=NULL){
        
        temp=current->next;
        current->next=current->prev;
        current->prev=temp;
        prev=current;
        current=current->prev;
    }
    head=prev;
    return head;
}




/************************************************ TEST CODE ********************************************************************/
#include <iostream>
using namespace std;


struct Node
   {
     int data;
     Node *next;
     Node *prev;
 };


Node* SortedInsert(Node *head,int data)
{
   Node* current = head;
   Node* prev = NULL;
   Node * newNode = new Node();
   newNode->data= data; 
   if(current==NULL){
       head=newNode;
       head->next=NULL;
       head->prev=NULL;
       return head;
   }
   while(current!=NULL){
       
       if(current->data>=newNode->data){
            Node* temp=current->prev;
    
		    if(temp==NULL){
		    	newNode->next=current;
		    	newNode->prev= temp;
		    	current->prev = newNode;
		    	head=newNode;
		    }
		    else if(temp){
		        temp->next=newNode;
				newNode->next=current;
		    	newNode->prev= temp;
		    	current->prev = newNode;
		    }  
           return head;
       }
       prev=current;
       current=current->next;
   } 
   
   newNode->prev=prev;
   newNode->next=NULL;
   current=newNode;
   prev->next=current;
   return head;
}


void printNodes(Node*head){
	
	
	if(!head){
		std::cout<<"NODE EMPTY"<<endl;
		return;
	}
	
	while(head!=NULL){
		std::cout<<head->data<<" ";
		head=head->next;
	}
	std::cout<<endl<<endl;
}


//NULL <-- 2 <--> 4 <--> 6 --> NULL , data = 5
int main() {
    Node * node1 = new Node();
    Node * node2 = new Node();
    Node * node3 = new Node();
    
    node1->data=2;
    node2->data=4;
    node3->data=6;
    
    node1->prev= NULL;
    node1->next=node2;
    node2->prev= node1;
    node2->next=node3;
    node3->prev= node2;
    node3->next=NULL;
    printNodes(node1);
    
    node1=SortedInsert(node1,11);
    printNodes(node1);
	return 0;
}