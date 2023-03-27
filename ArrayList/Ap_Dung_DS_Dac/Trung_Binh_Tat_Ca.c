#include "stdio.h"
#include "AListLib.c"

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
    putchar('\n');
    printf("%.3lf", getAvg(L));

}