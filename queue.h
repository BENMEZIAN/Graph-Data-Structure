#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int* arr;
}queue;

 
int isEmpty(queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}

void printQueue(queue* q){
	int i;
    if (q->f == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = q->f; q->r; i++)
            printf("%d ", q->arr[q->f]);
        printf("\n");
    }
}