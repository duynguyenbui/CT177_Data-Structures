#include "stdio.h"
#include "AListLib.c"

// Hàm nhập n phần tử vào danh sách từ bàn phím
void readList(int n,List *L){
    makenullList(L);
    for(int i = 0; i < n ; i++){
        scanf("%d",&L->Elements[i]);
        L->Last++;
    }
}

//  Hàm in danh sách
void printList(List L){
    Position P;
    P=first(L);
    while (P!= endList(L)){
        printf("%d ", retrieve(P,L));
        P=next (P,L);
    }
}

// Hàm xoá phần tử x đầu tiên
void erase(int x, List* pL) {
    int p = locate(x, *(pL));
    if(p != pL->Last +1) {
        deleteList(p, pL);
    }
}

int main() {
    List L;
    int n; scanf("%d", &n);
    readList(n, &L);
    int x; scanf("%d", &x);
    printList(L);
    erase(x, &L);
    putchar('\n');
    printList(L);

}