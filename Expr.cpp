// TUGAS VCLASS NO3
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
        
        if(strspn(chr, cSym) && sizeof(chr) == 1){ 
            x = num.back();
            num.pop_back();
            y = num.back();
            num.pop_back();

            if(chr[0] == '+'){
                num.push_back(y + x);
            }else if(chr[0] == '-'){
                num.push_back(y - x);
            }else if(chr[0] == '*'){
                num.push_back(y * x);
            }else if(chr[0] == '/'){
                num.push_back(y / x);
            }else if(chr[0] == '%'){
                num.push_back(fmod(y, x));
            }
        }else{
            num.push_back(atof(sprtd.c_str()));
        }
    }

    return num.back();
}
float Postfix(vector<string> _infix) 
{
    vector<string> postfix;
    string data;

    int i = 0;

    char cNum[] = "0123456789";
    char cSym[] = "()+-/%*";

    for(auto sprtd : _infix){
        char chr[strlen(sprtd.c_str())];
        strcpy(chr, sprtd.c_str());

        if(strspn(chr, cNum)){
            data += sprtd;
            postfix.push_back(data);
            data = "";
            }else if(chr[0] == '('){ //zahra
            Push(chr[0]);
        }else if(chr[0] == ')'){
            while(stk[top] != '('){
                data = Pop();
                postfix.push_back(data);
                data = "";
            }

            Pop();
        }else{
            bool skip = false;

            if((unsigned)i != _infix.size() && chr[0] == '-'){
                char nextChr[strlen(_infix[i + 1].c_str())];
                strcpy(nextChr, _infix[i + 1].c_str());

                if(i > 0){
                    char prevChr[strlen(_infix[i - 1].c_str())];
                    strcpy(prevChr, _infix[i - 1].c_str());
                    
                    if(strspn(prevChr, cSym)){
                        data = sprtd;
                        skip = true;
                    }
                }else if(strspn(nextChr, cNum)){
                    data = sprtd;
                    skip = true;
                }
            }
            
