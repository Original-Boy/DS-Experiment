#include <iostream>
#include <fstream>
#include<unistd.h>
using namespace std;
int main()
{
    ifstream ifile("data.txt");//如果使用相对路径请把data.txt放在下面代码输出的路径目录下，否则请使用data.txt的绝对路径。
    //输出可执行文件的路径。
    /*
    char buffer[256];
    char *val = getcwd(buffer, sizeof(buffer));
    if (val) {
        std::cout << buffer << std::endl;
    }
    */
    int n;
    ifile >> n;
    int matrix[15][15];//
    memset(matrix,0,sizeof(matrix));
    int a,b,c;
    while(ifile.good()){
        ifile>>a>>b>>c;
        matrix[a][b]=c;
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n;j++){
            if(j!=n-1) cout<<matrix[i][j]<<" ";
            else cout<<matrix[i][j]<<endl;
        }
    ifile.close();
    return 0;
}