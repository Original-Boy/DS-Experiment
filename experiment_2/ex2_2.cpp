#include<iostream>
#include<queue>
//输入时请把所有的null都换成-1
using namespace std;
const int ERROR = -1000;
typedef struct TNode * Position;
typedef Position BinTree;
struct TNode{
    int Data;
    BinTree Left;
    BinTree Right;
};
int read(){
    if(getchar() != '\n') {
        string x;
        cin >> x;
        int a = atoi(x.c_str());
        return a;
    }
    else return ERROR;
}
BinTree  CreatBinTree(){
    int Data;
    BinTree T,BT;
    queue<BinTree>q;

    //构建第一个节点
    cin>>Data;
    BT = (BinTree)malloc(sizeof(struct TNode));
    BT->Data = Data;
    BT->Left = BT->Right = nullptr;
    q.push(BT);
    while(!q.empty()){
        T=q.front();
        q.pop();
        if((Data = read()) == ERROR){
            T->Left = nullptr;
            break;
        }
        else{
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left=T->Left->Right=nullptr;
            if(Data != -1) q.push(T->Left);
        }
        if((Data = read()) == ERROR){
            T->Right = nullptr;
            break;
        }
        else{
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left=T->Right->Right=nullptr;
            if(Data != -1) q.push(T->Right);
        }
    }
    return BT;
}
BinTree BT0 = (BinTree)malloc(sizeof(struct TNode));
BinTree BTroot = BT0;
void InorderTraversal(BinTree BT){
    if(BT){
        InorderTraversal(BT ->Left);

        //构建新二叉树
        if(BT->Data != -1) {
            BTroot->Right = (BinTree) malloc(sizeof(struct TNode));
            BTroot->Right->Data = BT->Data;
            BTroot->Left = (BinTree) malloc(sizeof(struct TNode));
            BTroot->Left->Data = -1;
            BTroot = BTroot->Right;
        }
        InorderTraversal(BT -> Right);
    }
}
void LevelorderTraversal (BinTree BT){
    queue<BinTree>q;
    BinTree T;
    if(!BT) return;
    q.push(BT);
    while(!q.empty()){
        T=q.front();
        cout<<T->Data<<" ";
        q.pop();
        if(T->Left) q.push(T->Left);
        if(T->Right) q.push(T->Right);
    }
}
int main(){
    BinTree BT = CreatBinTree();
    InorderTraversal(BT);
    BT0 = BT0->Right;
    LevelorderTraversal(BT0);
    return 0;
}