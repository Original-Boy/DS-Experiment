#include <iostream>
#include<fstream>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void percdown(int A[],int p,int n){
    int parent,child;
    int x;
    x=A[p];
    for(parent =p;(parent*2+1)<n;parent=child){
        child=parent*2+1;
        if((child!=n-1)&&(A[child]<A[child+1])) child++;
        if(x>=A[child])break;
        else A[parent]=A[child];
    }
    A[parent]=x;
}
void heapsort(int A[],int N){
    int i;
    for(i=N/2-1;i>=0;i--){
        percdown(A,i,N);
    }
    for(i=N-1;i>0;i--){
        swap(&A[0],&A[i]);
        percdown(A,0,i);
    }
}
void bubblesort(int A[],int N)
{
    int p,i;
    bool flag;
    for(p=N-1;p>=0;p--){
        flag = false;
        for(i=0;i<p;i++){
            if(A[i]>A[i+1]){
                swap(&A[i],&A[i+1]);
                flag = true;
            }
        }
        if(!flag) break;
    }
}
void insertinosort(int A[],int N){
    int p,i;
    int tmp;
    for(p=1;p<N;p++){
        tmp=A[p];
        for(i=p;i>0&&A[i-1]>tmp;i--) A[i]=A[i-1];
        A[i] = tmp;
    }
}
void shellsort(int A[],int N){
    int si,d,p,i;
    int tmp;
    int sedgewick[]={929,505,209,109,41,19,5,1,0};
    for(si=0;sedgewick[si]>=N;si++);
    for(d=sedgewick[si];d>0;d=sedgewick[++si])
        for(p=d;p<N;p++){
            tmp=A[p];
            for(i=p;i>=d&&A[i-d]>tmp;i-=d)
                A[i]=A[i-d];
            A[i]=tmp;
        }
}
int main() {
    ifstream in("P1.txt");
    int type, num, data[100];
    in >> type;
    in >> num;
    for (int i = 0; i < num; i++) {
        in >> data[i];
    }
    if (type == 1) heapsort(data, num);
    else if (type == 2) bubblesort(data, num);
    else if(type==3) insertinosort(data,num);
    else shellsort(data,num);

    for (int i = 0; i < num; i++) {
        if (i == num - 1) cout << data[i];
        else cout << data[i] << " ";
    }
    return 0;
}


