//TUGAS VCLASS NO 2

#include <bits/stdc++.h> //Putri
using namespace std;

bool operate(char op){
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '%'   ){
        return true;
    }
    else{
        return false;
    }
}

int prioritas(string op){
    if(op == "+" || op == "-"   ){
        return 1;
    }
    else if(op == "*" || op == "/" ||  op == "%"   ){
        return 2;
    }
    return 0;
} 
