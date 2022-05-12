#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
bool u[10];
vector<int> route[10];
char data[10],letter,r1,r2;
int n;
void solve(int num){
    cout<< data[num]<< " ";
    for(int i = 0,sz = route[num].size(); i < sz;i++){
        if(!u[route[num][i]]){
            u[route[num][i]] = true;
            solve(route[num][i]);
        }

    }
}
int main(){
    ifstream ifile("data2.txt");
    ifile >> n;
    for(int i=0;i<n;i++){
        ifile >>letter;
        data[i]=letter;
    }
    while(ifile.good()){
        ifile >>r1>>r2;
        for(int i = 0; i < n;i++){
            if(data[i]==r1){
                for(int j=0;j<n;j++) {
                    if (data[j] == r2) {
                        route[i].push_back(j);
                    }
                }
            }
        }
    }
    solve(0);
    return 0;

}