

#ifndef LINKEDLIST_DATHUC_H
#define LINKEDLIST_DATHUC_H

#endif //LINKEDLIST_DATHUC_H
#include "stdio.h"
#include "stdlib.h"

typedef struct {
    double he_so;
    int bac;
} DonThuc;


//=== Khai Bao Da Thuc===//
struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;
//=== Khai báo đầu dòng==//
DaThuc khoitao();                                   //* Khởi tạo và trả về một đa thức rỗng
void chenDonThuc(DonThuc s, DaThuc *pD);            //* Hàm chèn đơn thức x vào đa thức chỉ bởi con trỏ pD
DaThuc nhapDaThuc();                                //* Trả về 1 đa thức nhập từ bàn phím
void inDaThuc(DaThuc d);                            //* Hiển thị đa thức d lên màn hình
DaThuc congDaThuc(DaThuc D1, DaThuc D2);            //* Hàm cộng 2 đa thức
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2);            //* Hàm nhân hai đa thức
DaThuc tinhDaoHam(DaThuc D);                        //* Hàm tính đạo hàm


//=== Khoi Tao Ham===//

// Hàm tạo List DaThuc
DaThuc khoitao(){
    DaThuc d;
    d=(struct Node*)malloc(sizeof(struct Node));
    d->Next=NULL;
    return d;
}


// Hàm chèn đơn thức x vào đa thức chỉ bởi con trỏ pD
void chenDonThuc(DonThuc s, DaThuc *pD){
    Position p=(*pD);
    int Found=0;
    while(p->Next!=NULL && !Found){
        if (p->Next->e.bac>s.bac)
            p=p->Next;
        else
            Found=1;
    }
    if (p->Next!=NULL){
        if(p->Next->e.bac==s.bac)
            p->Next->e.he_so += s.he_so;
        else {
            struct Node *t=(struct Node*)malloc(sizeof(struct Node));
            t->e=s;
            t->Next=p->Next;
            p->Next=t;
        }
    }
    else{
        struct Node *t=(struct Node*)malloc(sizeof(struct Node));
        t->e=s;
        t->Next=p->Next;
        p->Next=t;
    }
}

// Hàm in đa thức
void inDaThuc(DaThuc d){
    Position p=d;
    while(p->Next!=NULL){
        if (p->Next->Next==NULL)
            printf("%.3fX^%d",p->Next->e.he_so,p->Next->e.bac);
        else
            printf("%.3fX^%d + ",p->Next->e.he_so,p->Next->e.bac);
        p=p->Next;
    }
    printf("\n");
}

// Hàm nhập đa thức
DaThuc nhapDaThuc(){
    DaThuc d;
    DonThuc s;
    int n;
    d=khoitao();
    scanf("%d",&n);
    for (int i=1; i<=n; i++){
        scanf("%lf",&s.he_so);
        scanf("%d",&s.bac);
        chenDonThuc(s,&d);
    }
    return d;
}

// Hàm cộng hai đa thức
DaThuc congDaThuc(DaThuc D1, DaThuc D2){
    DaThuc d;
    d=khoitao();
    Position p=D1;
    while (p->Next!=NULL){
        chenDonThuc(p->Next->e,&d);
        p=p->Next;
    }
    p=D2;
    while (p->Next!=NULL){
        chenDonThuc(p->Next->e,&d);
        p=p->Next;
    }
    return d;
}

// Hàm nhân hai đa thức
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2){
    DaThuc d;
    DonThuc e,temp;
    d=khoitao();
    Position q,p;
    p=D1;
    while (p->Next!=NULL){
        e=p->Next->e;
        q=D2;
        while (q->Next!=NULL){
            temp.he_so = e.he_so * q->Next->e.he_so;
            temp.bac = e.bac + q->Next->e.bac;
            chenDonThuc(temp,&d);
            q=q->Next;
        }
        p=p->Next;
    }
    return d;
}

// Tính đạo hàm
DaThuc tinhDaoHam(DaThuc D){
    DaThuc dt;
    DonThuc e;
    dt=khoitao();
    Position p=D;
    while(p->Next!=NULL){
        e=p->Next->e;
        e.he_so *= e.bac;
        e.bac--;
        chenDonThuc(e,&dt);
        p=p->Next;
    }
    return dt;
}





