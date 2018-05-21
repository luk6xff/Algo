//QUEUE

//LINKED LIST IMPLEMENTATION

#include <stdio.h>
#include <stdlib.h>  



struct QNode{
	
	int key;
	struct QNode* next;
};


struct Queue{
    struct QNode *front, *rear;
};

//a function to creat a new node
struct QNode* newNode(int key){

    QNode* newNode= (struct QNode*) malloc(sizeof(struct QNode));

    newNode->key =key;
    newNode->next= NULL;
    return newNode;
}


// a function to create an empty queue
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct Queue*q, int k){
    //create a new LL node
    struct QNode* temp =newNode(k);
    
    if(q->rear==NULL){
        q->front = q->rear= temp;
        return;
    }
    q->rear->next =temp;
    q->rear=temp;
}

// a function to remove a key from given queue q
struct QNode *deQueue(struct Queue *q)
{
    if(q->front ==NULL)
        return NULL;
    
    //store previous front and move front one node ahead
    struct QNode *temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    return temp;
}


int main() {
    struct Queue *q = createQueue();
    enQueue(q, 10);
    enQueue(q, 20);
    deQueue(q);
    deQueue(q);
    enQueue(q, 30);
    enQueue(q, 40);
    enQueue(q, 50);
    struct QNode *n = deQueue(q);
    if (n != NULL)
      printf("Dequeued item is %d", n->key);
    return 0;
}