#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
#define MAX 20
using namespace std;

char stack[MAX];
int top = -1;

bool isFull(){
    return top == MAX - 1;
}

bool isEmpty(){
    return top == -1;
}

void Push(char p)
{
    if(!isFull())
    {
        stack[++top] = p;
    }
}

char Pop()
{
    char ch;

    if(!isEmpty())
    {
        ch = stack[top];
        stack[top] = '0';
        top--;
        return(ch);
    }

    return 0;
}

int Priority (char op) 
{
    if( op == '+' || op =='-')
    {
        return 1;
    }
 
    if( op == '*' || op =='/' || op == '%')
    {
        return 2;
    }

    return 0;
}

float Value(vector<string> _postfix){
    float x, y;
    vector<float> num;

    char cNum[] = "0123456789";
    char cSym[] = "+-/%*";

    for(auto sprtd : _postfix){
        char chr[strlen(sprtd.c_str())];
        strcpy(chr, sprtd.c_str());
