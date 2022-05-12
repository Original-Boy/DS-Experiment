#include <iostream>
#include <fstream>

using namespace std;
int dis[20][20];
int main(){
    ifstream ifile("data3.txt");
    int n,m;
    ifile >> n>>m;
    memset(dis,10,sizeof(dis));
    for(int i =1;i<=n;i++){
        dis[i][i]=0;
    }
    int p1,p2;
    for(int i=0;i<m;i++){
        ifile >> p1 >> p2;
        dis[p1][p2] = 1;
        dis[p2][p1] = 1;
    }
    for(int k=1;k<=n;k++)
        for(int i = 1; i <= n;i++)
            for(int j = 1; j <= n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
    for(int i=1;i<=n;i++){
        double temp=0;
        for(int j = 1; j <= n;j++){
            if(dis[i][j]<=6) temp+=1;
        }
        printf("%d:%.2f",i,temp/n*100);
        cout<<"%"<<endl;
    }
    return 0;
}