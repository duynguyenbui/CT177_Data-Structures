//
// Created by Duy Nguyen on 11/10/2022.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#endif //QUEUE_QUEUE_H
#include "stdio.h"
#include "stdlib.h"

//============Khai Bao QUEUE Theo LinkedList===============//
typedef int ElementType;
struct Node {
    ElementType Element;
    struct Node	*Next;
};
typedef struct Node* Position;
typedef struct {
    Position Front, Rear;
} Queue;

//==========Ham Co Ban=========//

// Ham Khoi Tao Queue
void makenullQueue(Queue *pQ) {
    Position Header;
    Header = (struct Node*) malloc(sizeof(struct Node));
    Header->Next = NULL;
    pQ->Front = Header;
    pQ->Rear = Header;
}

// Ham kiem tra Queue rong hay khong?
int emptyQueue(Queue Q) {
    return Q.Front== Q.Rear;
}

// Ham them mot phan tu vao cuoi Queue
void enQueue(ElementType X, Queue *pQ) {
    pQ->Rear->Next = (struct Node*) malloc(sizeof(struct Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Element = X;
    pQ->Rear->Next = NULL;
}

// Ham xoa phan tu khoi Queue
void deQueue(Queue *pQ) {
    if(!emptyQueue(*pQ)) {
        Position temp;
        temp = pQ->Front;
        pQ->Front =pQ->Front->Next;
        free(temp);
    } else {
        printf("Loi: Hang rong");
    }
}


// Ham lay phan tu o Front
ElementType front(Queue Q) {
    if(!emptyQueue(Q)) {
        return Q.Front->Next->Element;
    } else {
        printf("Loi, hang rong");
        return -1;
    }
}

// Kiem tra Queue co bao nhieu phan tu

int countElements(Queue Q){
    Position P=Q.Front;
    int count=0;
    while(P!=Q.Rear){
        count++;
        P=P->Next;
    }
    return count;
}

// Nhap Va Xuat Queue
void readQueue(int n,Queue *pQ) {
    int i;
    ElementType X;
    makenullQueue(pQ);
    for(i=1;i<=n;i++) {
        scanf("%d",&X);
        enQueue(X, pQ);
    }
}

void printQueue(Queue Q) {
 	while (!emptyQueue(Q)) {
 		printf("%d ",front(Q));
 		deQueue(&Q);
 	}
 	printf("\n");
}

//Main
int main() {
    Queue Q1,Q2;
    int n,count=0;
    scanf("%d",&n);
    readQueue(n,&Q1);
    readQueue(n,&Q2);
    while(!emptyQueue(Q1)){
        if(!emptyQueue(Q2)){
            if(front(Q1)==front(Q2)){
                deQueue(&Q1);
                deQueue(&Q2);
                count++;
            }
            else{
                enQueue(front(Q1),&Q1);
                deQueue(&Q1);
                count++;
            }
        }
    }
    printf("%d\n",count);
    return 0;
}


