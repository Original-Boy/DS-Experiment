#include <iostream>
#include<cmath>
using namespace std;
typedef struct SNode1 *numstack;
typedef struct SNode2 *symstack;
struct SNode1{
    double *data;
    int Top;
    int maxsize;
};
typedef numstack nums;
struct SNode2{
    char *sym;
    int Top;
    int maxsize;
};
typedef symstack syms;
nums numcreate(int maxsize){
    numstack num = (numstack)malloc(sizeof(struct SNode1));
    num->data = (double*)malloc(sizeof(double)*maxsize);
    num->Top=-1;
    num->maxsize = maxsize;
    return num;
}
syms symcreate(int maxsize) {
    symstack symbol = (symstack) malloc(sizeof(struct SNode2));
    symbol->sym = (char *) malloc(sizeof(char) * maxsize);
    symbol->Top = -1;
    symbol->maxsize = maxsize;
    return symbol;
}
int getPriority(char ch) {
    int level = 0; // 优先级

    switch(ch) {
        case '(':
            level = 1;
            break;
        case '+':
        case '-':
            level = 2;
            break;
        case '*':
        case '/':
            level = 3;
            break;
        default:
            break;
    }
    return level;
}

bool isOperator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false; // 否则返回false
}
bool IsFull(nums a){
    return(a->Top==a->maxsize-1);
}
bool IsFull(syms a){
    return(a->Top==a -> maxsize - 1);
}
bool push(nums a,double x){
    if(IsFull(a)){
        printf("the stack is full");
        return false;
    }
    else{
        a->data[++(a->Top)] = x;
        return true;
    }
}
bool push(syms a,char x){
    if(IsFull(a)){
        printf("the stack is full");
        return false;
    }
    else{
        a->sym[++(a->Top)] = x;
        return true;
    }
}
char top(syms a){
    return a->sym[a->Top];
}
bool IsEmpty(nums a){
    return (a->Top==-1);
}
bool IsEmpty(syms a){
    return (a->Top==-1);
}
double Pop(nums a){
    if(IsEmpty(a)){
        printf("the stack is empty");
        return -1000000;
    }
    else{
        return(a->data[(a -> Top)--]);
    }
}
char Pop(syms a){
    if(IsEmpty(a)){
        printf("the stack is empty");
        return '?';
    }
    else{
        return(a->sym[(a -> Top)--]);
    }
}
int main(){
    nums number = numcreate(100);
    syms symbol = symcreate(100);
    int length;
    char tempchar[255];//ch用来存储操作符
    cin.getline(tempchar,255);
    length = (int)strlen(tempchar); //strlen输出unsigned long
    int i=0;
    double num;

    while(i<length){
        if(isdigit(tempchar[i])){
            num = 0;
            do{
                num = num * 10 + (tempchar[i]-'0');
                i++;
            } while (isdigit(tempchar[i]));
            push(number,num);
        }
        else if (tempchar[i]=='.'){
            i++;
            num = 0;
            int temp=-1;
            do{
                num = num + (tempchar[i]-'0')*pow(10,temp);
                i++;
            }while(isdigit(tempchar[i]));
            double t = Pop(number);
            t = t + num;
            push(number,t);
        }
        else if(tempchar[i]=='('){
            push(symbol,tempchar[i]);
            i++;
        }

        else if(isOperator(tempchar[i])){
            if(IsEmpty(symbol)){
                push(symbol,tempchar[i]);
                i++;
            }
            else{
                while(!IsEmpty(symbol)){
                    if(getPriority(tempchar[i])> getPriority(top(symbol))){
                        break;
                    }
                    else {
                        char c = Pop(symbol);
                        double tem1= Pop(number);
                        double tem2 = Pop(number);
                        if (c == '+') {
                            push(number, tem2 + tem1);
                        } else if (c == '-') {
                            push(number, tem2 - tem1);
                        } else if (c == '*') {
                            push(number, tem2 * tem1);
                        } else if (c == '/') {
                            push(number, tem2 / tem1);
                        }
                    }

            }//while结束
                push(symbol,tempchar[i]);
                i++;
        }
    }

        else if(tempchar[i]==')'){
            while(top(symbol) !='('){

                char c = Pop(symbol);
                double tem1 = Pop(number);
                double tem2 = Pop(number);
                if (c == '+') {
                    push(number, tem2 + tem1);
                } else if (c == '-') {
                    push(number, tem2 - tem1);
                } else if (c == '*') {
                    push(number, tem2 * tem1);
                } else if (c == '/') {
                    push(number, tem2 / tem1);
                }
            }
            Pop(symbol);
            i++;//把左括号弹出
        }
        else{
            i++;//过滤空格
        }
    }
    while(!IsEmpty(symbol)){
        char c = Pop(symbol);
        double tem1 = Pop(number);
        double tem2 = Pop(number);
        if (c == '+') {
            push(number, tem2 + tem1);
        } else if (c == '-') {
            push(number, tem2 - tem1);
        } else if (c == '*') {
            push(number, tem2 * tem1);
        } else if (c == '/') {
            push(number, tem2 / tem1);
        }

    }
    cout<<Pop(number);

    return 0;

}
