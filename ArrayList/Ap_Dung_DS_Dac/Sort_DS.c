#include "stdio.h"
#include "AListLib.c"


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(List *L){
    for (int i = 0; i < L->Last; i++){
        for (int j = L->Last - 1; j >= 0; j--){
            if(j > i){
                if(L->Elements[j] < L->Elements[j-1]){
                    swap(&L->Elements[j],&L->Elements[j-1]);
                }
            }
        }
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

// Hàm nhập n phần tử vào danh sách từ bàn phím
void readList(int n,List *L){
    makenullList(L);
    for(int i = 0; i < n ; i++){
        scanf("%d",&L->Elements[i]);
        L->Last++;
    }
}

int main() {
    List L;
    int n;
    scanf("%d", &n);
    readList(n, &L);
    printList(L);
    bubbleSort(&L);
    putchar('\n');
    printList(L);

}