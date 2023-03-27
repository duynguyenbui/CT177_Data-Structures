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

// Hàm tối ưu danh sách
void normalize(List *L) {
    int  i = 0;
    int j;
    while (i != L->Last){
        j = i + 1;
        while (j != L->Last){
            if(L->Elements[i] == L->Elements[j]){
                deleteList(j + 1,L);
            }
            else{
                j++;
            }
        }
        i++;
    }
}

// Hàm kiểm tra phần tử có trong danh sách
int member(int x, List L) {
    if(locate(x, L) == L.Last+1) {
        return 0;
    }
    return 1;
}


// Hàm chèn vào vị trí cuối
void insertSet(int x, List *pL){
    pL->Elements[pL->Last] = x;
    (pL->Last)++;
}


void unionSet(List L1, List L2, List *pL){
    makenullList(pL);
    Position P;
    P=1;
    while (P!=L1.Last+1){
        insertSet(L1.Elements[P-1], pL);
        P++;
    }
    P=1;
    while (P!=L2.Last+1){
        if (!member(L2.Elements[P-1],*pL))
            insertSet(L2.Elements[P-1], pL);
        P++;
    }
}

int main() {
    List L1, L2, L3;
    makenullList(&L3);
    int m, n;
    scanf("%d", &m);
    readList(m, &L1);
    scanf("%d", &n);
    readList(n, &L2);
    normalize(&L1);
    normalize(&L2);
    unionSet(L1, L2, &L3);
    printList(L1);
    putchar('\n');
    printList(L2);
    putchar('\n');
    printList(L3);
}