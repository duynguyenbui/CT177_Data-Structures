// cai dat hang bang phuong phap tinh tien
// khai bao hang
#include<stdio.h>

#define MaxLength 10
typedef int ElementType;
typedef struct
{
    ElementType Element[MaxLength];
    int Front, Rear;

}Queue;

// tao hang rong
void MakeNull_Queue(Queue *Q)
{
    Q->Front=-1;
    Q->Rear=-1;
}

// kiem tra hang rong
int Empty_Queue (Queue Q)
{
    return Q.Front==-1;
}

// kiem tra hang day
int Full_Queue (Queue Q)
{
    return (Q.Rear-Q.Front+1)==MaxLength;
}

//them phan tu vao hang
void EnQueue (ElementType X, Queue *Q)
{
    if (!Full_Queue(*Q))
    {  if(Empty_Queue(*Q)) Q->Front=0;
        if(Q->Rear==MaxLength-1)
        {
            // di chuyen tinh tuyen ra truoc Front -1 vi tri
            for(int i=Q->Front;i<=Q->Rear;i++)
                Q->Element[i-Q->Front]=Q->Element[i];
            // xac dinh vi tri rear moi
            Q->Rear=MaxLength-Q->Front-1;
            Q->Front=0;
        }
        // tang rear de luu noi dung moi
        Q->Rear=Q->Rear+1;
        Q->Element[Q->Rear]=X;
    }
    else printf("loi: hang day");

}

//xoa phan tu ra khoi hang
void DeQueue( Queue *Q)
{
    if(! Empty_Queue(*Q))
    {
        Q->Front=Q->Front+1;
        if (Q->Front>Q->Rear)
            MakeNull_Queue(Q);

    }
    else printf("loi: hang rong");
}

// lay noi dung tai vi tri dau hang
ElementType Front(Queue Q)
{
    return Q.Element[Q.Front];

}

//nhap du lieu cho hang
void ReadQueue (Queue *Q)
{
    MakeNull_Queue(Q);
    ElementType X;
    int n;
    printf("\n\n hang co bao nhieu phan tu ?");
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        printf("phan tu thu %d: ",i);
        scanf("%d",&X);
        EnQueue(X,Q);
    }

}

// 	hien thi hang
void PrintQueue(Queue *Q)
{
    while (!Empty_Queue (*Q))
    {
        printf("%d", Front(*Q));
        DeQueue(Q);
    }
    printf("\n");
}