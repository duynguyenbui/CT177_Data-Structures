// Khai bao danh sach dac
#include<stdio.h>
#define Maxlength 30
/*===================   Khai bao danh sach dac  ========================*/
typedef int ElementType;
typedef int Position;
typedef struct{
    ElementType Elements[Maxlength];
    Position Last;
}List;
/* ====================Ket thuc khai bao================================*/
//Khai bao dau dong

// Hàm chuẩn
void makenullList(List *L);                                     //* Hàm tạo danh sách rỗng
int emptyList(List L);                                          //* Hàm kiểm tra danh sách rỗng?
int fullList(List L);                                           //* Hàm kiểm tra danhn sách đầy?
Position first(List L);                                         //* Hàm trả về vị trí đầu trong danh sách(Vị trí = 1, index = 0)
Position endList(List L);                                       //* Hàm trả về vị trí cuối trong danh sách(Vị trí bằng = Last+1, index = Last)
Position next(Position p, List l);                              //* Hàm trả về vị trí kế tiếp tại vị trí P trong danh sách(Vị trí = P+1, index = P)
Position previous(Position p, List L);                          //* Hàm trả về vị trí trước tại vị trí P trong danh sách(Vị trí = P-1, index = P-2)
ElementType retrieve(Position p, List L);                       //* Hàm trả về nội dung tại vị trí P trong danh sách
void insertList(ElementType X, Position P, List *L);            //* Hàm chèn một phần tử tại vị trí P(Chỉ số = P- 1)
void deleteList(int P, List *pL);                               //* Hàm xoá một phần tử tại vị trí P(Chỉ số = P-1)
Position locate(ElementType X, List L);                         //* Hàm trả về vị trí của phần tử X(Chỉ số = P-1)

// Hàm bổ sung
void printList(List L);                                         //* Hàm in danh sách
void readList(List *L);                                         //* Hàm nhập n phần tử vào danh sách từ bàn phím
int locate1(int x, List L);                                     //* Hàm trả về vị trí của phần tử từ cuối
void insertSet(int x, List *pL);                                //* Hàm chèn vào vị trí cuối
int member(int x, List L);                                      //* Hàm kiểm tra phần tử có trong danh sách không?
void readSet(List *L);                                          //* Hàm nhập vào phần tử từ bàn phím "chèn cuối"
void intersection(List L1, List L2, List *pL);                  //* Hàm tìm giao của 2 List
void removeAll(int x, List *pL);                                //* Hàm xoá tất cả phần tử có giá trị x
void difference(List L1, List L2, List *pL);                    //* Hàm tìm hiệu của 2 tập hợp và chèn vào danh sách mới
void erase(int x, List* pL);                                    //* Hàm xoá phần tử x đầu tiên
void splitList(List L1, List *L2, List *L3);                    //* Hàm chia 1 List thành 2 List chẵn, lẻ
void filter_evenNumber(List L1,List *L);                        //* Hàm lọc phần tử chẵn vào một danh sách
void filter_oddNumber(List L1,List *L);                         //* Hàm lọc phần tử lẻ vào một danh sách
void normalize(List *L);                                        //* Hàm tối ưu danh sách
void unionSet(List L1, List L2, List *pL);                      //* Tìm hợp của 2 danh sách và lưu vào một danh sách
void changeList(List L1,List *L);                               //* Hàm chuyển 1 danh sách qua danh sách mới
void mergeList(List L1,List L2,List *L);                        //* Gộp 2 danh sách vào 1 danh sách
void copyEvenNumbers(List L1, List *pL2);                       //* Chép tất cả các số chẵn trong danh sách L1 sang danh sách chỉ bởi con trỏ pL2
void printOddNumbers(List L);                                   //* Ham in ra so le trong danh sach

//*=========== Hàm Chuẩn ===========*//
// Hàm tạo danh sách rỗng
void makenullList(List *L){
    L->Last =0;
}

// Hàm kiểm tra danh sách rỗng?
int emptyList(List L){
    return (L.Last==0);
}

// Hàm kiểm tra danhn sách đầy?
int fullList(List L){
    return (L.Last==Maxlength);
}

// Hàm trả về vị trí đầu trong danh sách(Vị trí = 1, index = 0)
Position first(List L){
    return 1;
}

//Hàm trả về vị trí cuối trong danh sách(Vị trí bằng = Last+1, index = Last)
Position endList(List L){
    return L.Last + 1;
}

//Hàm trả về vị trí kế tiếp tại vị trí P trong danh sách(Vị trí = P+1, index = P)
Position next(Position p, List l){
    return p+1;
}

//Hàm trả về vị trí trước tại vị trí P trong danh sách(Vị trí = P-1, index = P-2)
Position previous(Position p, List L){
    return p-1;
}

// Hàm trả về nội dung tại vị trí P trong danh sách
ElementType retrieve(Position p, List L){
    return L.Elements[p-1];
}

// Hàm chèn một phần tử tại vị trí P(Chỉ số = P- 1)
void insertList(ElementType X, Position P, List *L){
    int i=0;
    if(L->Last == Maxlength)
        printf("\n danh sach day!!!");
    else if ((P<1) || (P>L->Last+1) )
        printf("\n vi tri khong hop le !!!");
    else{
        for(i=L->Last ; i>=P; i--)
            L->Elements[i]=L->Elements[i-1];
        L->Last++;
        L->Elements[P-1]=X;
    }
}

// Hàm xoá một phần tử tại vị trí P(Chỉ số = P-1)
void deleteList(int P, List *pL) {
    if(P> pL->Last || P < 1) {
        printf("Vi tri khong hop le\n");
    } else if (pL->Last == 0) {
        printf("Danh sach rong\n");
    } else {
        for(int i = P-1; i < pL->Last-1; i++) {
            pL->Elements[i] = pL->Elements[i+1];
        }
        pL->Last--;
    }
}

// Hàm trả về vị trí của phần tử X(Chỉ số = P-1). Nếu không tìm thấy trả về Last + 1
Position locate(ElementType X, List L){
    Position P;
    int found=0;
    P =first(L);
    while ((P!=endList(L)) && (found==0)){
        if(retrieve(P,L)==X)
            found =1;
        else P =next (P,L);
    }
    return P;
}

//*=========== Hàm Bổ Sung ===========*//
//  Hàm in danh sách
void printList(List L){
    Position P;
    P=first(L);
    while (P!= endList(L)){
        printf("%d ", retrieve(P,L));
        P=next(P,L);
    }
}

// Hàm nhập n phần tử vào danh sách từ bàn phím
void readList(List *L){
    makenullList(L);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        scanf("%d",&L->Elements[i]);
        L->Last++;
    }
}

// Hàm trả về vị trí của phần tử từ cuối
int locate1(int x, List L)
{
    int p=L.Last;
    int found = 0;
    while (p>0 && found == 0)
        if (L.Elements[p-1]==x) found=1;
        else p=p-1;
    if (found) return p;
    else return L.Last+1;
}

// Hàm chèn vào vị trí cuối
void insertSet(int x, List *pL){
    pL->Elements[pL->Last] = x;
    (pL->Last)++;
}

// Hàm kiểm tra phần tử có trong danh sách
int member(int x, List L) {
    if(locate(x, L) == L.Last+1) {
        return 0;
    }
    return 1;
}

// Hàm nhập vào phần tử từ bàn phím "chèn cuối"
void readSet(List *L){
    makenullList(L);
    int n, x;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++ ) {
        scanf("%d", &x);
        if(!member(x, *L)) {
            insertSet(x, L);
        }
    }
}

// Hàm tìm giao của 2 List
void intersection(List L1, List L2, List *pL) {
    makenullList(pL);
    for (int i = 0; i < L1.Last; i++) {
        if(member(L1.Elements[i], L2)) {
            insertSet(L1.Elements[i], pL);
        }
    }
}

// Hàm xoá tất cả phần tử có giá trị x
void removeAll(int x, List *pL) {
    while(locate(x, *pL) != pL->Last+1) {
        deleteList(locate(x, *pL), pL);
    }
}

// Hàm tìm hiệu của 2 tập hợp và chèn vào danh sách mới
void difference(List L1, List L2, List *pL) {
    makenullList(pL);
    for (int i = 0; i < L1.Last; i++) {
        if (!member(L1.Elements[i], L2)){
            insertSet(L1.Elements[i], pL);
        }
    }
}

// Hàm xoá phần tử x đầu tiên
void erase(int x, List* pL) {
    int p = locate(x, *(pL));
    if(p != pL->Last +1) {
        deleteList(p, pL);
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

// Hàm chia 1 List thành 2 List chẵn, lẻ
void splitList(List L1, List *L2, List *L3) {
    Position P=first(L1);
    makenullList(&(*L2));
    makenullList(&(*L3));
    while (P!=endList(L1))
    {
        if( retrieve(P,L1)%2==0)
            insertList(retrieve(P,L1),first(*L2),L2);
        else
            insertList(retrieve(P,L1),first(*L3),L3);
        P=next(P,L1);
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

// Tìm hợp của 2 danh sách và lưu vào một danh sách
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

// Ham chuyen mot danh sach sang mot danh sach
void changeList(List L1,List *L){
    for(int i = 0 ; i < L1.Last ; i++){
        insertList(L1.Elements[i],L->Last,L);
    }
}

// Ham merge hai danh sach lai voi nhau
void mergeList(List L1,List L2,List *L){
    changeList(L1,L);
    changeList(L2,L);
}

// Ham copy cac so le va luu vao mot danh sach
void copyEvenNumbers(List L1, List *pL2) {
    makenullList(pL2);
    int k = 1;
    for(int i = 0 ; i < L1.Last; i++){
        if(L1.Elements[i] % 2 == 0){
            insertList(L1.Elements[i],k,pL2);
            k++;
        }
    }
}

// Ham in ra so le trong danh sach
void printOddNumbers(List L){
    for (int i = 0; i < L.Last; i++){
        if(L.Elements[i] % 2 != 0) {
            printf("%d ",L.Elements[i]);
        }
    }
}


