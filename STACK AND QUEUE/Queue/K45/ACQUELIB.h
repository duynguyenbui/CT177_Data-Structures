//cai dat hang bang mang vong
#include<stdio.h>
#include "stdlib.h"
// khai bao ham cai dat bang mang vong
#define MaxLength 10
typedef int ElementType;
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

// tao hang rong
void MakeNull_Queue(Queue*Q){
    Q->Front=-1;
    Q->Rear=-1;
}

// kiem tra hang rong
int Empty_Queue(Queue Q)
{
    return Q.Front== -1;
}

// kiem tra hang day
int Full_Queue(Queue Q)
{
    return (Q.Rear-Q.Front+1) % MaxLength==0;
}

// them phan tu vao hang
void EnQueue ( ElementType X,Queue *Q)
{
    if(!Full_Queue(*Q))
    {
        if (Empty_Queue(*Q)) Q->Front=0;
        Q->Rear=(Q->Rear+1)% MaxLength;
        Q->Elements[Q->Rear]=X;
    }
    else printf("loi: hang day");
}

// xoa phan tu ra khoi hang
void DeQueue(Queue*Q)
{
    if(!Empty_Queue(*Q))
    {
        if (Q->Front==Q->Rear) MakeNull_Queue(Q);
        else Q->Front=(Q->Front+1)% MaxLength;

    }
    else printf(" loi : hang rong");
}

//lay noi dung phan tu tai vi tri dau hang
ElementType Front(Queue Q)
{
    return Q.Elements[Q.Front];

}


//tao du lieu cho hang
void ReadQueue (Queue *Q)
{
    MakeNull_Queue(Q);
    ElementType X;
    for(int i=0;i<10;i++)
    {
        printf("phan tu thu %d: ",i);
        scanf("%d",&X);
        EnQueue(i,Q);
    }
}

// hien thi hang ra man hinh
void PrintQueue (Queue *Q)
{
    while (!Empty_Queue(*Q))
    {
        printf("%d",Front(*Q));
        DeQueue(Q);

    }
    printf("\n\n");
}