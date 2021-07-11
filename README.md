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
            if(isdigit(k[i]) || //putri
           (k[i] == '-' &&
            i == 0 &&
            isdigit(k[i+1]))){
            
            temp.push_back(k[i]);
            continue;
        }
        if(operate(k[i])){ 
            if(temp.length() != 0){
                
                infix.push_back(temp);
                temp.clear();
            }
            if((k[i] == '-' &&
                operate(k[i-1])) ||
               (k[i] == '-' &&
                i == 0 && k[i+1] == '(') ||
               (k[i] == '-' &&
                k[i-1] == '(')){
                
                infix.push_back("-1");
                infix.push_back("*");
            }else{
                infix.push_back(k.substr(i, 1));
            }
        }
    } 
    if(temp.length() != 0){
        infix.push_back(temp);
        temp.clear();
    }
} 
                              
void InfixtoPostfix(){ //zahra
    stack <string> temp2;
    int i = 0;
    for(remake = infix.begin(); remake != infix.end() ; remake++, i++){
        if(isdigit(infix[i].back())){
            postfix.push_back(infix[i]);
            continue;
        }
        if(infix[i] == ")"){ //putri
            while(!temp2.empty() &&
                  (temp2.top() != "(")){
                
                string toPush = temp2.top();
                postfix.push_back(toPush);
                temp2.pop();
            }
            temp2.pop();
            continue;
        } //zahra
        if(operate(infix[i][0])){
            if(temp2.empty() ||
               temp2.top() == "("){
               temp2.push(infix[i]);
            }
            else{ //putri
                while(!temp2.empty() &&
                     (temp2.top() != "(") &&
                      grande(infix[i], temp2.top())){
                    
                    string toPush = temp2.top();
                    postfix.push_back(toPush);
                    temp2.pop();
                }
                temp2.push(infix[i] );
            }
            continue;
        }
        } //zahra
    while(!temp2.empty()){
        string toPush = temp2.top();
        postfix.push_back(toPush);
        temp2.pop();
    }
}
