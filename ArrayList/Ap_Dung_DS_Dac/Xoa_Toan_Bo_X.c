#include "stdio.h"
#include "AListLib.c"

void readList(int n,List *L){
    makenullList(L);
    for(int i = 0; i < n ; i++){
        scanf("%d",&L->Elements[i]);
        L->Last++;
    }
}

void printList(List L){
    Position P;
    P=first(L);
    //printf("bat dau in danh sach ");
    while (P!= endList(L)){
        printf("%d ", retrieve(P,L));
        P=next (P,L);
    }
    //printf("\n ket thuc in ra danh sach \n ");
}


int main() {
    List L;
    int n; scanf("%d", &n);
    readList(n, &L);
    int x; scanf("%d", &x);
    printList(L);
    while (locate(x, L) != L.Last+1) {
        deleteList(locate(x, L), &L);
    }
    putchar('\n');
    printList(L);
}
