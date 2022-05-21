#include <fstream>
#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int median3(int A[],int left,int right){
    int center=(left+right)/2;
    if(A[left]>A[center]) swap(&A[left],&A[center]);
    if(A[left]>A[right]) swap(&A[left],&A[right]);
    if(A[center]>A[right]) swap(&A[center],&A[right]);
    swap(&A[center],&A[right-1]);
    return A[right-1];
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
void Qsort(int A[],int left,int right){
    int pivot,cutoff,low,high;
    if(cutoff<=right-left){
        pivot=median3(A,left,right);
        low=left;
        high=right-1;
        while(1){
            while(A[++low]<pivot);
            while(A[--high]>pivot);
            if(low<high) swap(&A[low],&A[high]);
            else break;
        }
        swap(&A[low],&A[right-1]);
        Qsort(A,left,low-1);
        Qsort(A,low+1,right);
    }
    else insertinosort(A+left,right-left+1);
}
void Quicksort(int A[],int N){
    Qsort(A,0,N-1);
}
int main(){
    ifstream in("P2.txt");
    int num;
    in>>num;
    int data[100];
    for(int i = 0; i < num; i++){
        in >>data[i];
    }
    Quicksort(data,num);
    for(int i = 0; i < num;i++){
        if(i==num-1) cout<<data[i];
        else cout<<data[i]<<" ";
    }
    return 0;
}