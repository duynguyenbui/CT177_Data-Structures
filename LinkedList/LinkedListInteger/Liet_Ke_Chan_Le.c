#include <math.h>
#include "PListLib.c"
void ReadList(List *L)
{
    makenullList(L);
    int n, x;
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        insertList(x,endList(*L),L);
    }
    return ;
}

void InDS( List L)
{
    Position p=L;
    if (p->Next ==NULL) printf("DS rong");
    while (p->Next!= NULL)
    {
        printf("%d ", retrieve(p,L));
        p=next(p,L);
    }
    printf("\n");
    return ;
}
void InDSle( List L)
{
    Position p=L;
    int f=0;
   // if (p->Next ==NULL) printf("DS rong");
    while (p->Next!= NULL)
    {   
        if (((int) fabs(retrieve(p,L)))%2==1)
            {printf("%d ", retrieve(p,L));
            f=1;}
        p=next(p,L);
    }
    if (f==0) printf("DS rong");
    printf("\n");
    return ;
}
void InDSchan( List L)
{
    Position p=L;
    int f=0;
   // if (p->Next ==NULL) printf("DS rong");
    while (p->Next!= NULL)
    {   
        if (((int) fabs(retrieve(p,L)))%2==0)
            {printf("%d ", retrieve(p,L)); f=1;}
        p=next(p,L);
    }
    if (f==0) printf("DS rong");
    printf("\n");
    return ;
}
int main()
{
    List L;
    ReadList(&L);
    InDS(L);
    InDSle(L);
    InDSchan(L);
    return 0;
}