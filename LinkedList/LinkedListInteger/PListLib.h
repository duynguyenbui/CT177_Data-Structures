#include<stdio.h>
#include "stdlib.h"

/*================= Khai bao danh sach lien ket luu tru cac so nguyen =========*/
typedef int ElementType;
struct Node{
    ElementType Element;
     struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

/* =========Khai báo đầu dòng===========*/
//========Hàm Cơ Bản=======//
void makenullList(List *Header);                            //* Hàm tạo danh sách rỗng có con trỏ đầu mục
int emptyList(List L);                                      //* Hàm kiểm tra rỗng
void insertList(ElementType X, Position P, List *L);        //* Hàm thêm phần tử vào DSLK tại con trỏ P+1
void deleteList(Position P, List*L);                        //* Hàm xoá phần tử khỏi DSLK xoá tại con trỏ P+1;
Position locate(ElementType X, List L);                     //* Hàm tìm con trỏ chứa X trong danh sách (Không có trả vè con trỏ trỏ tới vị trí cuối cùng P->Next = NULL);
ElementType retrieve(Position P, List L);                   //* Hàm lấy nội dung tại con trỏ P+1
Position first(List L);                                     //* Hàm trả về con trỏ đầu mục L
Position endList(List L);                                   //* Hàm trả về con trỏ cuối P->Next = NULL
void readList(List *L);                                     //* Hàm nhập DSLK
void printList(List L);                                     //* Hàm in DSLK
//=======Hàm Bổ Sung=======//
void append(ElementType X, List *pL);                       //* Hàm chèn vào cuối
void addFirst(ElementType X, List *pL);                     //* Hàm chèn vào đầu DSLK L+1
void erase(ElementType X, List *pL);                        //* Hàm xoá phần tử X đầu tiên
void removeAll(ElementType X, List *pL);                    //* Hàm xoá tất cả phần tử X trong DSLK
void normalize(List *pL);                                   //* Hàm tối ưu DSLK
void printOddNumbers(List L);                               //* Hàm in ra số lẻ trong DSLK
void copyEvenNumbers(List L1, List *pL);                    //* Hàm chuyển số chẵn sang danh sách mới
double getAvg(List L);                                      //* Hàm tính trung bình tất cả các phần tử trong DSLK
int member(ElementType X, List L);                          //* Hàm kiểm tra phần tử có thuộc DSLK
List readSet();                                             //* Hàm ghi vào Set
List unionSet(List L1, List L2);                            //* Hàm tìm hợp của 2 danh sách
List intersection(List L1, List L2);                        //* Hàm tìm giao của 2 danh sách
List difference(List L1, List L2);                          //* Hàm tìm hiệu của 2 danh sách
void sort(List *pL);                                        //* Hàm sắp xếp danh sách

//=======Khởi tạo hàm=======//
// Hàm tạo danh sách rỗng có con trỏ đầu mục
void makenullList(List *Header){
    (*Header)=(struct Node*)malloc(sizeof(struct Node));
    (*Header)->Next = NULL;
}

// Hàm kiểm tra rỗng
int emptyList(List L){
    return (L->Next ==NULL);
}

// Hàm thêm phần tử vào DSLK tại con trỏ P+1
void insertList(ElementType X, Position P, List *pL){
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    //Position t=(struct Node*)malloc(sizeof(struct Node));
    t->Element=X;
    t->Next=P->Next;
    P->Next=t;
}

// Hàm xoá phần tử khỏi DSLK xoá tại con trỏ P+1;
void deleteList(Position p, List *pL)
{
    if (p->Next!=NULL) {
        Position t=p->Next;
        p->Next = t->Next;
        free(t);
    }
}

// Hàm tìm con trỏ chứa X trong danh sách (Không có trả vè con trỏ trỏ tới vị trí cuối cùng P->Next = NULL);
Position locate(ElementType X, List L){
    Position P=L;
    int Found = 0;
    while ((P->Next!=NULL) && (!Found)){
        if (P->Next->Element==X)
            Found=1;
        else
            P=P->Next;
    }
    return P;
}

// Hàm lấy nội dung tại con trỏ P+1
ElementType retrieve(Position P, List L){
    if(P->Next!=NULL)
        return P->Next->Element;
}


// Hàm trả về con trỏ đầu mục L
Position first(List L){
    return L;
}

// Hàm trả về con trỏ cuối P->Next = NULL
Position endList(List L){
    Position P;
    P=L;
    while(P->Next!=NULL) {
        P=P->Next;
    }
    return P;
}

// Hàm nhập từ bàn phím
void readList(List *L){
    int n;
    makenullList(L);
    ElementType X;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",&X);
        insertList(X, endList(*L),L);
    }
}

// Hàm in danh sách
void printList(List L){
    Position P=L;
    while (P->Next!=NULL){
        printf("%d ",P->Next->Element);
        P=P->Next;
    }
    printf("\n");
}

//======= Hàm Bổ Sung =======//
// Hàm chèn vào cuối
void append(ElementType X, List *pL){
    Position P=(*pL);
    while (P->Next!=NULL)
        P=P->Next;
//  insertList(X,P,pL);
   struct Node* t=(struct Node*)malloc(sizeof(struct Node));
	t->Element=X;
	t->Next=P->Next;
	P->Next=t;
}

// Hàm chèn vào đầu DSLK L+1;
void addFirst(ElementType X, List *pL){
    Position P=(*pL);
    struct Node* t=(struct Node*)malloc(sizeof(struct Node));
    t->Element=X;
    t->Next=P->Next;
    P->Next=t;
    (*pL)=P;
}

// Hàm xoá phần tử X đầu tiên
void erase(ElementType X, List *pL){
    Position P=locate(X,*pL);
    if (P->Next!=NULL)
        deleteList(P, pL);
    else
        printf("Not found %d\n",X);
}

// Hàm xoá tất cả phần tử X trong DSLK
void removeAll(ElementType X, List *pL){
    Position P=locate(X,*pL);
    while (P->Next!=NULL){
        deleteList(P, pL);
        P=locate(X,*pL);
    }
}

// Hàm tối ưu DSLK
void normalize(List *pL){
    Position P, Q;
    P=(*pL);
    while (P->Next != NULL){
        Q=P->Next;
        while (Q->Next != NULL){
            if (P->Next->Element == Q->Next->Element)
                deleteList(Q,pL);
            else
                Q=Q->Next;
        }
        P=P->Next;
    }
}

// Hàm in ra số lẻ
void printOddNumbers(List L){
    Position P=L;
    while (P->Next!=NULL){
        if (P->Next->Element%2==1)
            printf("%d ", P->Next->Element);
        P=P->Next;
    }
}

// Hàm chuyển số chẵn sang danh sách mới
void copyEvenNumbers(List L1, List *pL){
    makenullList(pL);
    Position P=L1;
    while (P->Next!=NULL){
        if(P->Next->Element%2==0)
            append(P->Next->Element,pL);
        P=P->Next;
    }
}

// Hàm tính trung bình tất cả các phần tử trong DSLK
double getAvg(List L){
    Position P=L;
    if (P->Next==NULL)
        return -10000.000;
    else {
        double S=0;
        int count=0;
        while (P->Next!=NULL){
            S += P->Next->Element;
            P=P->Next;
            count++;
        }
        return S/count;
    }
}

// Hàm kiểm tra phần tử có thuộc DSLK
int member(ElementType X, List L){
    int Found=0;
    Position P=L;
    while (P->Next!=NULL && !Found){
        if (P->Next->Element==X)
            Found=1;
        else
            P=P->Next;
    }
    return Found;
}

// Hàm ghi vào Set
List readSet(){
    List L;
    int n;
    ElementType X;
    makenullList(&L);
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&X);
        if (!member(X,L))
            addFirst(X,&L);
    }
    return L;
}
// Hàm tìm hợp của 2 danh sách
List unionSet(List L1, List L2){
    List L;
    makenullList(&L);
    Position P=L1;
    while (P->Next!=NULL){
        append(P->Next->Element,&L);
        P=P->Next;
    }
    P=L2;
    while (P->Next!=NULL){
        if (!member(P->Next->Element,L))
            append(P->Next->Element,&L);
        P=P->Next;
    }
    return L;
}
// Hàm tìm giao của 2 danh sách
List intersection(List L1, List L2){
    List L;
    makenullList(&L);
    Position P=L1;
    while (P->Next!=NULL){
        if (member(P->Next->Element,L2))
            append(P->Next->Element,&L);
        P=P->Next;
    }
    return L;
}
// Hàm tìm hiệu của 2 danh sách
List difference(List L1, List L2){
    List L;
    makenullList(&L);
    Position P=L1;
    while (P->Next!=NULL){
        if (!member(P->Next->Element,L2))
            append(P->Next->Element,&L);
        P=P->Next;
    }
    return L;
}
// Hàm sắp xếp danh sách
void sort(List *pL){
    Position P,Q;
    ElementType temp;
    P=(*pL);
    while (P->Next!=NULL){
        Q=P->Next;
        while(Q->Next!=NULL){
            if (P->Next->Element>Q->Next->Element){
                temp=P->Next->Element;
                P->Next->Element=Q->Next->Element;
                Q->Next->Element=temp;
            }
            Q=Q->Next;
        }
        P=P->Next;
    }
}
