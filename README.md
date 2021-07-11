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
bool grande(string op, string s){ 
    int Nilai1, Nilai2;
    Nilai1 = prioritas(op); Nilai2 = prioritas(s);
    
    return Nilai1 <= Nilai2;
}

vector <string> infix; vector <string> postfix; string temp; vector <string>::iterator remake; vector <string>::iterator itu;

void MasukkanData(){
    string k;
    char h;
    while(cin.get(h)){
        if(h == '\n'){
            break;
        }
        if(h != ' '){
            k.push_back(h);
        }
    }
    int length = k.length(); 
    for(int i = 0; i < length; i++){
        if(k[i] == '(' ||
           k[i] == ')'){
            if(temp.length() != 0){
                infix.push_back(temp);
                temp.clear();
            }
            infix.push_back(k.substr(i, 1)); 
