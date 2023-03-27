

#ifndef LINKEDLIST_STUDENTLIST_H
#define LINKEDLIST_STUDENTLIST_H

#endif //LINKEDLIST_STUDENTLIST_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


// Khai báo danh sách
typedef struct {
    char ID[10];
    char Name[50];
    float R1, R2, R3;
}Student;
struct Node
{
    Student Element;
    struct Node* Next;
};
typedef struct Node* List;

//Khai báo đầu dòng
List getList();                                                                         //* Khởi tạo danh sách sinh viên
struct Node *locate(char s[], List L);                                                  //* Hàm trả về con trỏ tới sinh viên cần tìm
int append(Student s, List *pL);                                                        //* Hàm tạo một Node cuối cùng
List readList();                                                                        //* Hàm nhập danh sách sinh viên
List getFailedList(List L);                                                             //* Hàm lọc sinh viên dưới 4 ra một danh sách
void printList(List L);                                                                 //* Hàm in danh sách sinh viên
void showPassedList(List L);                                                            //* Hàm hiển thị đạt



// Thực thi hàm cơ bản
List getList(){
    List L;
    L=(struct Node*)malloc(sizeof(struct Node));
    L->Next=NULL;
    return L;
}

// Hàm trả về con trỏ tới sinh viên cần tìm
struct Node *locate(char s[], List L){
    struct Node *P=L;
    int Found=0;
    while (P->Next!=NULL && !Found){
        if (strcmp(P->Next->Element.ID,s)==0)
            Found=1;
        else
            P=P->Next;
    }
    return P;
}

// Hàm tạo một Node cuối cùng
int append(Student s, List *pL){
    struct Node *P, *temp;
    P=locate(s.ID,(*pL));
    if (P->Next!=NULL){
        return 0;
    }
    else{
        temp=(struct Node*)malloc(sizeof(struct Node));
        temp->Element=s;
        temp->Next=NULL;
        P->Next=temp;
        return 1;
    }
}

// Hàm nhập danh sách sinh viên
List readList() {
    int n,i;
    Student s;
    char st[50];
    List L = getList(); // Khởi tạo danh sách rỗng
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf(" "); //skip some characters
        fgets(st,10,stdin);
        if (st[strlen(st)-1] == '\n')
            st[strlen(st)-1] = '\0';
        strcpy(s.ID, st);
        fgets(st,50,stdin);
        if (st[strlen(st)-1] == '\n')
            st[strlen(st)-1] = '\0';
        strcpy(s.Name, st);
        scanf("%f%f%f",&s.R1,&s.R2,&s.R3);
        // Nếu mã sinh viên chưa có thì chèn vào danh sách
        int flag=append(s,&L);
        if (!flag)
            printf("%s exists\n",s.ID);
    }
    return L;
}

// Hàm lọc sinh viên dưới 4 ra một danh sách
List getFailedList(List L) {
    List L2;
    L2=getList();
    struct Node *p=L;
    float avg;
    while(p->Next!=NULL){
        avg=(p->Next->Element.R1+p->Next->Element.R2+p->Next->Element.R3)/3;
        if (avg<4.0){
            append(p->Next->Element, &L2);
        }
        p=p->Next;
    }
    return L2;
}

// Hàm in danh sách sinh viên
void printList(List L) {
    struct Node *p=L;
    int count=1;
    float avg;
    while(p->Next!=NULL){
        avg=(p->Next->Element.R1+p->Next->Element.R2+p->Next->Element.R3)/3;
        printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",count,p->Next->Element.ID,
               p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
               p->Next->Element.R3, avg);
        count++;
        p=p->Next;
    }
}

// Hàm hiển thị đạt
void showPassedList(List L) {
    struct Node *p=L;
    int count=0;
    float avg;
    while(p->Next!=NULL){
        avg=(p->Next->Element.R1+p->Next->Element.R2+p->Next->Element.R3)/3;
        if (avg>=4.0){
            printf(" %d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n",count+1,p->Next->Element.ID,
                   p->Next->Element.Name, p->Next->Element.R1, p->Next->Element.R2,
                   p->Next->Element.R3, avg);
            count++;
        }
        p=p->Next;
    }
    printf("%d students in total\n",count);
}

