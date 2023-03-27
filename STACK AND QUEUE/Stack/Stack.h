//
// Created by Duy Nguyen on 10/10/2022.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#endif //STACK_STACK_H
#include "stdio.h"
#include "stdlib.h"

//Khai bao STACK
#define SoPhanTu 100
#define M SoPhanTu
typedef struct {
    int DuLieu[SoPhanTu];
    int Dinh;// Note:  Dinh se co gia tri luu index nhung nguoc chieu cua STACK
} NganXep;

//===============Cac Ham Co Ban===============//
// Khoi tao ngan xep(Dinh = SoPhanTu) => Ngan xep nguoc
void khoitao(NganXep *pS){
    pS->Dinh=SoPhanTu;
}

// Kiem tra ngan xep rong
int ktRong(NganXep Stack){
    return Stack.Dinh==SoPhanTu;
}

//Kiem tra ngan xep day
int ktDay(NganXep Stack){
    return (Stack.Dinh==0);
}

// Them 1 phan tu vao ngan xep
void them(int x, NganXep *pStack) {
    if(pStack->Dinh!= 0){ // Kiem tra day
        pStack->Dinh--;
        pStack->DuLieu[pStack->Dinh] = x;
    }
}

//Xoa 1 phan tu khoi ngan xep
void xoa(NganXep *pStack ) {
    if(pStack->Dinh != SoPhanTu) {
        pStack->Dinh++;
    }
}

// Ham lay gia tri cua dinh
int giatriDinh(NganXep Stack) {
    if(Stack.Dinh != SoPhanTu) {
        return Stack.DuLieu[Stack.Dinh];
    } else {
        printf("Loi, hang rong\n");
        return -1;
    }
}

// Hien thi toan bo STACK, POP ra toan bo => Ngan xep rong
void hienthi(NganXep *pStack) {
    while (!ktRong(*pStack)) {
        printf("%d ", giatriDinh(*pStack));
        xoa(pStack);
    }
}

// Ham chuyen doi so nhi phan vao STACK
void doiNhiPhan(int n, NganXep *pStack) {
    khoitao(pStack);
    while (n!= 0) {
        them(n%2, pStack);
        n=n/2;
    }
    hienthi(pStack);
}





