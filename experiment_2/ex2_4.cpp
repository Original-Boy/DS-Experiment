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
BinTree ans = nullptr;
int judge = 0;
int temp1=0,temp2=0;
void Inorder(BinTree BT,int a,int b){
    if(BT){
        Inorder(BT->Left,a,b);
        Inorder(BT->Right,a,b);
        if(BT->Data ==a) temp1 = 1;
        if(BT->Data ==b) temp2 = 1;

    }

}
//说明：从底至顶遍历二叉树，而对每一个二叉树节点，都遍历其子树，若子树中同时含有2个元素，则证明是共同祖先，而由于是从底至顶的，所以第一个满足条件的一定是最近的祖先
void InorderTraversal(BinTree BT,int a,int b){
    if(BT){
        //整体上看是后序遍历
        InorderTraversal(BT->Left,a,b);
        InorderTraversal(BT->Right,a,b);
        temp1=0,temp2=0;
        Inorder(BT,a,b);//对当前节点做一次遍历
        if(temp1==1 && temp2 ==1 && judge == 0){
            ans = BT;
            judge ++;
        }
        }
}
int main(){
    BinTree BT = CreatBinTree();
    int a,b;
    cin>>a;
    cin>>b;
    InorderTraversal(BT,a,b);
    cout<<ans->Data;
}