#include <iostream>
//输入时请把所有的null都换成-1
using namespace std;
#define MaxTree 10
const int ERROR = -1000;
typedef struct TNode * Position;
typedef Position BinTree;
struct TNode{
    int Data;
    BinTree Left;
    BinTree Right;
};
struct TreeNode
{
    char Element ;
    int Left ;
    int Right ;
} Tree1[MaxTree],Tree2[MaxTree];

int BuildeTree(struct TreeNode T[])
{
    int i,N,check[MaxTree];
    int Root,cl,cr;
    cin>>N;

    if(N!=0)
    {
        for( i=0;i<N;i++) check[i] = 0 ;
        for( i=0;i<N;i++)
        {
            cin>>T[i].Element>>cl>>cr;

            if(cl!=-1)
            {
                T[i].Left=cl ;
                check[T[i].Left]=1 ;
            }
            else T[i].Left=-1 ;

            if(cr!=-1)
            {
                T[i].Right =cr ;
                check[T[i].Right]=1 ;
            }
            else T[i].Right=-1 ;
        }
    }
    else
        return  -1 ;

    for(i=0;i<N;i++ )
    {
        if(check[i]==0 )//只有根节点才满足这一条件
            break ;
    }
    Root=i ;

    return  Root ;
}
int Isomorphic(int R1, int R2)
{
    if((R1==-1)&&(R2==-1))
        return 1;
    if(((R1==-1)&&(R2!=-1))||((R2==-1)&&(R1!=-1)))
        return 0;
    if(Tree1[R1].Element!=Tree2[R2].Element)
        return 0;
    else
    {
        if(Isomorphic(Tree1[R1].Left,Tree2[R2].Left)&&Isomorphic(Tree1[R1].Right,Tree2[R2].Right))
            return 1;
        else if(Isomorphic(Tree1[R1].Left,Tree2[R2].Right)&&Isomorphic(Tree1[R1].Right,Tree2[R2].Left))
            return 1;
        else
            return 0;
    }
}

int main(  )
{
    int Root1 , Root2 ;
    Root1 = BuildeTree( Tree1 ) ;
    Root2 = BuildeTree( Tree2 ) ;


    if( Isomorphic( Root1,Root2 ) )
        cout<<"True";
    else
        cout<<"False";
    return 0 ;

}  

