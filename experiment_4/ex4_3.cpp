#include <iostream>
#include <fstream>
using namespace std;
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
void shellsort(int A[],int N){
    int si,d,p,i;
    int tmp;
    int sedgewick[]={929,505,209,109,41,19,5,1,0};
    for(si=0;sedgewick[si]>=N;si++);
    for(d=sedgewick[si];d>0;d=sedgewick[++si])
        for(p=d;p<N;p++){
            tmp=A[p];
            for(i=p;i>=d&&A[i-d]<tmp;i-=d)
                A[i]=A[i-d];
            A[i]=tmp;
        }
}
int main(){
    ifstream in("P3.txt");
    int data[100],k,num,i=0;
    do {
        in>>num;
        data[i++]=num;
    }
    while( num != -1);
    i--;
    shellsort(data,i);
    in >> k;
    cout<<data[k-1];
    return 0;
}