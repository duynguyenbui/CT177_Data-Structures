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

// Hàm lọc phần tử lẻ vào một danh sách
void filter_oddNumber(List L1,List *L){
    int k = 1;
    for (int i = 0; i < L1.Last; i++){
        if(L1.Elements[i] % 2 != 0){
            insertList(L1.Elements[i],k,L);
            k++;
        }
    }
}
int main() {
    List L1, L2, L3;
    makenullList(&L2);
    makenullList(&L3);
    int n;
    scanf("%d", &n);
    readList(n, &L1);
    filter_oddNumber(L1, &L2);
    filter_evenNumber(L1, &L3);
    printList(L1);
    putchar('\n');
    printList(L2);
    putchar('\n');
    printList(L3);
}