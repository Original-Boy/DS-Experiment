#include <iostream>

using namespace std;

typedef struct Node * PtrToNode;
struct Node{
    int Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode * PtrToQNode;
struct QNode {
    Position Front,Rear;
    int Maxsize = 10000;
};
typedef PtrToQNode Queue;

bool IsEmpty(Queue Q1){
    return (Q1->Front == NULL);
}

int DeleteQ(Queue Q1){
    Position FrontCell;
    int FrontElem;

    if(IsEmpty(Q1)){
        printf("队列空");
        return -10000000;
    }

    else{
        FrontCell = Q1->Front;
        if(Q1->Front == Q1->Rear)
            Q1->Front=Q1 -> Rear=NULL;
        else Q1->Front=Q1->Front->Next;
        FrontElem = FrontCell->Data;
        free(FrontCell);
        return FrontElem;
    }

}//DeleteQ可以返回队首的元素
int AddQ(Queue Q1, int x){
    Position tmp;
    tmp = (Position)malloc(sizeof(struct Node));
    Q1->Rear->Next = tmp;
    Q1->Rear = Q1 -> Rear -> Next;
    Q1->Rear->Data = x;

}
Queue CreateQueueQ(){
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Front = (Position)malloc(sizeof(struct Node));
    Q ->Rear = Q->Front;
    Q->Front->Data = 100000;
    return Q;
}
int main(){
    //构建列表
    Queue Q = CreateQueueQ();
    Queue QAns = CreateQueueQ();
    int n,num;
    cin>>n;
    cin>>num;
    Q->Rear->Data = num;
    for(int i = 0; i < n-1; i++){
        cin>>num;
        AddQ(Q,num);
    }

    for(int i =0;i<n-1;i++){//每个循环会拿两个值的 所以要跑总长度-1
        int m1= DeleteQ(Q);
        for(int j = i;j <n-1;j++ ){
            int m2 = DeleteQ(Q);
            if(!IsEmpty(Q)) {
                if (m1 < m2) {
                    AddQ(Q, m2);
                } else {
                    AddQ(Q, m1);
                    m1 = m2;
                }
            }
            else{//这是为了防止把一个元素填入到空的队列中去
                if (m1 < m2) {
                    AddQ(QAns, m1);
                    m1 = m2;
                } else {
                    AddQ(QAns, m2);

                }
            }
        }
        AddQ(QAns,m1);
    }
    DeleteQ(QAns);//目的是释放Queue中第一个结点

    for(int i = 0; i < n-1; i++){
        cout<<DeleteQ(QAns)<<' ';
    }
    cout<<DeleteQ(QAns);
    return 0;
}