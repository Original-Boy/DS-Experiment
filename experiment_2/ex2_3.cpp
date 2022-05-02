#include <iostream>
#include <queue>
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
int temp=-2,judge=0;
int InorderTraversal(BinTree BT){
    if(BT){
        InorderTraversal(BT ->Left);
        if(BT->Data != -1){
            if(temp>BT->Data) judge = 1;
            temp = BT->Data;
        }
        InorderTraversal(BT -> Right);
    }
    return judge;
}
int main(){
    BinTree BT = CreatBinTree();
    int j = InorderTraversal(BT);
    if(j) cout<<"False";
    else cout<<"True";
    return 0;
}