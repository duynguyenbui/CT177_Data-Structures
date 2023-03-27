#include "stdio.h"
#include "AListLib.c"

//  Hàm in danh sách
void printList(List L){
    Position P;
    P=first(L);
    while (P!= endList(L)){
        printf("%d ", retrieve(P,L));
        P=next (P,L);
    }
}

// Hàm nhập n phần tử vào danh sách từ bàn phím
void readList(int n,List *L){
    makenullList(L);
    for(int i = 0; i < n ; i++){
        scanf("%d",&L->Elements[i]);
        L->Last++;
    }
}

// Hàm lọc phần tử chẵn vào một danh sách
void filter_evenNumber(List L1,List *L){
    int k = 1;
    for(int i = 0 ; i < L1.Last; i++){
        if(L1.Elements[i] % 2 == 0){
            insertList(L1.Elements[i],k,L);
            k++;
        }
    }
}

// Hàm tính giá trị trung bình
float getAvg(List L){
    float result = 0;
    if(L.Last == 0) {
        return -10000.0000;
    } else {
        for (int i = 0; i < L.Last; i++){
            result += L.Elements[i];
        }
        return result/L.Last;
    }
}
int main() {
    List L, L1;
    int n;
    scanf("%d", &n);
    readList(n, &L);
    makenullList(&L1);
    filter_evenNumber(L, &L1);
    printList(L);
    putchar('\n');
    printList(L1);
    printf("\n%.3lf", getAvg(L1));
}