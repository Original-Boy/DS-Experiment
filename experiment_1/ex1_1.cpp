#include <iostream>

using namespace std;


int main(){
    int a=0,b=0;
    while(scanf("%d %d",&a,&b)!=EOF) {
        if (b != 0) {
            cout << a * b <<' '<< b - 1 << endl;
        }
        else{
            break;
        }
    }
}

