/*============= cai dat bang mang==================*/
/* khai bao*/
#include<stdio.h>
#define MaxLength 100

typedef int ElementType;
typedef struct{
    ElementType Elements[MaxLength];
    int Top_idx;

}Stack;

/* tao ngan xep rong*/
void MakeNull_Stack( Stack* S){
    S-> Top_idx =MaxLength;
}

/* kiem tra ngan xep rong*/
int Empty_Stack (Stack S){
    return (S.Top_idx == MaxLength);
}

/* kiem tra ngan xep day*/
int Full_Stack(Stack S){
    return (S.Top_idx ==0);
}

/* lay noi dung phan tu tai dinh cua ngan xep*/
ElementType Top(Stack S){
    if (!Empty_Stack(S))
        return S.Elements[S.Top_idx];
    else{
        printf("\n loi! Stack rong");
        return NULL;
    }
}

/* them phan tu vao ngan xep*/
void Push (ElementType X, Stack *S){
    if (Full_Stack(*S))
        printf("\n loi , stack khong the nhap them");
    else{
        S->Top_idx=(S->Top_idx -1);
        S->Elements[S->Top_idx]=X;

    }
}

/* xoa phan tu khoi ngan xep*/
void Pop(Stack *S){
    if (Empty_Stack(*S))
        printf(" loi, Stack rong");
    else{
        S->Top_idx =(S->Top_idx +1);

    }
}