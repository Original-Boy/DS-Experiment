#include <iostream>

using namespace std;

typedef struct LNode * PtrToLNode;
struct LNode{
    int Data;
    PtrToLNode Next;
};
typedef  PtrToLNode Position;
typedef  PtrToLNode List;

void show(List R){
    R = R -> Next;
    while(R != nullptr){
        cout<<R ->Data<<' ';
        R = R -> Next;
    }
}

int main(){
    int a,b;
    List L1,L2;
    Position L1_Head = nullptr, L2_Head = nullptr;
    L1 = (Position)malloc(sizeof(struct LNode));
    L2 = (Position)malloc(sizeof(struct LNode));
    L1_Head = L1;
    L2_Head = L2;

    while(cin>>a){
        Position tmp;
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp -> Data = a;
        L1 -> Next = tmp;
        L1 = L1 -> Next;
        if(cin.get() == '\n') break;
    }
    L1 = L1_Head->Next;
    while(cin>>b){
        Position tmp;
        tmp = (Position)malloc(sizeof(struct LNode));
        tmp -> Data = b;
        L2 -> Next = tmp;
        L2 = L2 -> Next;
        if(cin.get() == '\n')  break;
    }
    L2 = L2_Head->Next;


    Position temp = nullptr,head = nullptr;
    head = (Position)malloc(sizeof (struct LNode));
    temp = head;
    while (L1 != nullptr  &&  L2 != nullptr){
        if(L1->Data < L2->Data) {
            temp -> Next = L1;
            L1 = L1 -> Next;
            temp = temp -> Next;
        }
        else {
            temp -> Next = L2;
            L2 = L2 -> Next;
            temp = temp -> Next;
        }
    }
    if(L1 == nullptr){
        temp -> Next = L2;
    }
    else{
        temp -> Next = L1;
    }

    //显示新的升序列表
    show(head);

}