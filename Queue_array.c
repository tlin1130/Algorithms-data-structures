/*

Queue_array.c is an array implemtation of queue that stores an int item.

*/


#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h>

// A structure to represent a queue
typedef struct Queue{
	int front;
	int rear;
	int size;
    int capacity;
    int* array;
}Queue;

// Creates a queue with given capacity
Queue* createQueue(int capacity){ 
    Queue* queue = (Queue*) malloc(sizeof(Queue)); 
    queue->capacity = capacity; 
    queue->front = 0;
    queue->size = 0;  
    queue->rear = capacity - 1;   
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 

// Returns 1 if queue is full. Otherwise, 0
int isFull(Queue* queue){
    return (queue->size == queue->capacity);
}

// Returns 1 if queue is empty. Otherwise, 0
int isEmpty(Queue* queue){
    return queue->size == 0;
}

// Adds item into queue 
void enqueue(Queue* queue, int item){ 
    if (isFull(queue)){
        printf("Failed to enqueue item: %d\n", item);
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    printf("Item: %d enqueued to queue\n", item); 
} 

// Returns and removes an item from queue 
int dequeue(struct Queue* queue){ 
    if (isEmpty(queue)){
        printf("Dequeue() operation failed\n");
        return INT_MIN; 
    }
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1) % queue->capacity; 
    queue->size = queue->size - 1;
    printf("Item: %d dequeued from queue\n", item); 
    return item; 
} 

// Returns item at front of queue
int front(Queue* queue){
    if (isEmpty(queue)){
        printf("front() operation failed.\n");
        return INT_MIN; 
    }
    return queue->array[queue->front]; 
}

// Returns item at rear of queue
int rear(Queue* queue){
    if (isEmpty(queue)){
        printf("rear() operation failed.\n");
        return INT_MIN; 
    }
    return queue->array[queue->rear]; 
}

// This function prints each item in queue from front end to rear end
void printQueue(Queue* queue){
    if (isEmpty(queue)){
        printf("printQueue() operation failed\n");
        return; 
    }
    printf("Size of queue: %d\n", queue->size);
    int i;
    i = queue->front;
    while(i != queue->rear){
        printf("item: %d, ", queue->array[i]);   
        i = (i + 1) % queue->capacity;
    }
    printf("item: %d\n", queue->array[queue->rear]);
}

// main function to test queue operations
int main(){

    Queue* q = createQueue(5); 
    enqueue(q, 10); 
    enqueue(q, 20); 
    enqueue(q, 30); 
    enqueue(q, 40);
    enqueue(q, 50);
    dequeue(q);
    dequeue(q);
    enqueue(q, 10); 
    enqueue(q, 20);
    printQueue(q);

    return 0;
}

