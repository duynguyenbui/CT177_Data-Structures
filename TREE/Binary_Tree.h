#ifndef TREE_BSTREE_H
#define TREE_BSTREE_H

#endif //TREE_BSTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
struct Node{
    KeyType Key;
    struct Node *Left;
    struct Node *Right;
};
typedef struct Node *Tree;

// ========== Một số hàm cơ bản ======== //

//* Tạo rỗng Tree
void makeNullTree(Tree *root){
    (*root) = NULL;
}

//* Tạo và trả về một cây rỗng
Tree initTree() {
    Tree T = NULL;
    return T;
}

//* Kiểm tra cây rỗng
int isEmpty(Tree T){
    return T== NULL;
}

//* Chèn node vào Tree
void insertNode(int x,Tree *root){
    Tree temp = *root;
    if(temp == NULL){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->Key = x;
        temp->Left = NULL;
        temp->Right = NULL;
        *root = temp;
    }
    else{
        if(temp->Key == x){
            return;
        }
        else if(temp->Key > x){
            insertNode(x,&temp->Left);
        }
        else{
            insertNode(x,&temp->Right);
        }
    }
}

//* Tạo Tree
Tree createTree(){
    Tree root;
    int n;
    scanf("%d",&n);
    makeNullTree(&root);
    int x;
    for (int i = 0; i < n; i++){
        scanf("%d",&x);
        insertNode(x,&root);
    }
    return root;
}

//* Duyệt tiền tự
void preOrder(Tree root){
    if(root != NULL){
        printf("%d ",root->Key);
        preOrder(root->Left);
        preOrder(root->Right);
    }
}

//* Duyệt trung tự
void inOrder(Tree root){
    if(root != NULL){
        inOrder(root->Left);
        printf("%d ",root->Key);
        inOrder(root->Right);
    }
}

//* Duyệt hậu tự
void posOrder(Tree root){
    if(root != NULL){
        posOrder(root->Left);
        posOrder(root->Right);
        printf("%d ",root->Key);
    }
}

//* Node nhỏ nhất trong Tree
Tree minNode(Tree root){
    while (root->Left != NULL){
        root = root->Left;
    }
    return root;
}

//* Node lớn nhất trong Tree
Tree maxNode(Tree root){
    while (root->Right != NULL){
        root = root->Right;
    }
    return root;
}

//* Node phía trước khi duyệt trung tự
Tree getPrevious(int x,Tree root){
    Tree prevNode = NULL;
    while (root != NULL){
        if(root->Key > x){
            root = root->Left; // Hy vong x nam ben trai
        }
        else if(root->Key < x){ // Hy vong x nam ben phai => Luu lai Node cu
            prevNode = root;
            root = root->Right;
        }
        else if(root->Left == NULL){ // Tim thay x node trai X bang NULL tra ve Node Cha
            return prevNode;
        }
        else{
            return maxNode(root->Left); // Tra ve Node lon nhat ben trai
        }
    }
    return NULL;
}

//* Duyệt trung tự vào 1 mảng
void LNRtoArray(int *i,int M[],Tree root){
    if(root != NULL){
        LNRtoArray(&*i,M,root->Left);
        M[*i] = root->Key;
        *i = *i + 1;
        LNRtoArray(&*i,M,root->Right);
    }
}

//* Tìm 1 node trong cây
Tree searchNode(int x,Tree root){
    if(root != NULL){
        if(root->Key == x){
            return root;
        }
        else if(root->Key > x)
            return searchNode(x,root->Left);
        else
            return searchNode(x,root->Right);
    }
    else{
        return NULL;
    }
}

//* Node phía sau khi duyệt trung tự
Tree getNext(int x,Tree root){
    int n = 0;
    int M[50];
    int pos;
    LNRtoArray(&n,M,root);
    for (int i = 0; i < n; i++){
        if(x == M[i]){
            pos = i;
            break;
        }
    }
    Tree result = searchNode(M[pos+1],root);
    return result;
}

// Tree getNext(int x,Tree T){
//     Tree p=T,lright=NULL;
//     while (p!=NULL){
//         if (p->Key==x){
//             if (p->Right==NULL) return lright;
//             else return minNode(p->Right);
//         }
//         else
//             if (x<p->Key) {
//                 lright=p;
//                 p=p->Left;}
//             else {
//                 p=p->Right;
//             }
//     }
//     return NULL;
// }


void searchStandFor(Tree *node1,Tree *node2){ // Ham noi hai root
    if((*node2)->Left != NULL){
        searchStandFor(&(*node1),&(*node2)->Left);
    }
    else{
        (*node1)->Key = (*node2)->Key;
        (*node1) = (*node2);
        (*node2) = (*node2)->Right;
    }
}

//* Xoá một Node có khoá X trong cây
//int deleteNode(int x,Tree *root){ // Thay bang be nhat ben phai
//    Tree temp = *root;
//    if(temp == NULL){
//        return 0;
//    }
//    if(temp->Key > x){
//        return deleteNode(x,&temp->Left);
//    }
//    else if(temp->Key < x){
//        return deleteNode(x,&temp->Right);
//    }
//    else{
//        Tree p = *root;
//        if(temp->Left == NULL){
//            temp = temp->Right;
//        }
//        else{
//            if(temp->Right == NULL){
//                temp = temp->Left;
//            }
//            else{
//                searchStandFor(&p,&(*root)->Right);
//            }
//        }
//        p = NULL;
//        *root = temp;
//    }
//    return 1;
//}

// =========== Ham xoa CTU =========== //

//* Xoá một Node có khoá X trong cây

int deleteMin(Tree *T) { // Thay bang be nhat ben phai
    int k;
    if((*T)->Left == NULL) {
        k = (*T)->Key;
        (*T) = (*T)->Right;
        return k;
    } else return deleteMin(&(*T)->Left);
}

void deleteNode(int x, Tree *T){
    if((*T)!=NULL) {
        //Kiem tra cay khac rong
        if (x < (*T)->Key)    //Hy vong x nam ben trai cua nut
            deleteNode(x, &(*T)->Left);
        else if (x > (*T)->Key)   //Hy vong x nam ben phai cua nut
            deleteNode(x, &(*T)->Right);
        else{   // Tim thay khoa x tren cay
            if (((*T)->Left == NULL) && ((*T)->Right == NULL))    //x la nut la
                (*T) = NULL; // Xoa nut x
            else // x co it nhat mot con
            if ((*T)->Left == NULL)   //Chac chan co con phai
                (*T) = (*T)->Right;
            else if ((*T)->Right == NULL)     //Chac chan co con trai
                (*T) = (*T)->Left;
            else      // x co hai con
                (*T)->Key = deleteMin(&(*T)->Right);
        }  
    }
}


//* Tìm ra con phải của khoá X không có khoá trả về NULL
Tree rightSibling(int x,Tree root){
    Tree temp = NULL;
    while (root != NULL){
        if(root->Key > x){
            temp = root->Right;
            root = root->Left;
        }
        else if(root->Key < x){
            temp = root->Left;
            root = root->Right;
        }
        else{
            // root->Key == x
            return temp;
        }
    }
    return NULL;
}

//* Hàm trả về chiều cao của cây
int getHeight(Tree root){
    if(root == NULL){
        return -1;
    }
    else{
        int heightLeft = getHeight(root->Left);
        int heightRight = getHeight(root->Right);
        if(heightLeft > heightRight)
            return heightLeft+1;
        else
            return heightRight+1;
    }
}

//* In đường dẫn tới khoá X trong cây
void printPath(int x, Tree T)
{
    int temp;

    if(T!=NULL){ //Kiem tra cay rong
        temp = T->Key;
        printf("%d ", temp);
        if(x == temp) //tim thay khoa
            //return T;
            printf("-> Tim thay");
        else if(x<temp) // Hy vong K nam ben trai
            printPath(x,T->Left);
        else // Hy vong K nam ben phai
            printPath(x,T->Right);
    }else //return NULL;
        printf("-> Khong thay");
}



//* Hàm trả về cha của khoá X trong cây
Tree getParent(int x, Tree T) {
    Tree P = T, Parent = NULL;
    while ( P !=  NULL) {
        if (P->Key == x) return Parent;
        Parent = P;
        if(P->Key > x) P = P->Left;
        else P= P->Right;
    }
    return NULL;
}

//* Tìm chiều cao của nút có khoá X trên cây
int hNode(int x, Tree T){
    Tree pT=searchNode(x, T);
    if(pT==NULL) return -1;
    else return getHeight(pT);
}
