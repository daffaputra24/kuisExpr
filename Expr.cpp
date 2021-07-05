#include <bits/stdc++.h>
using namespace std;
 
bool op(char oper){
	if(oper == '*' || oper == '+' || oper == '-' || oper == '/'){
		return true;
	}else{
		return false;
	}
}

bool isOperator1(char c){  
   return (!isalpha(c) && !isdigit(c));  
}  

int getPriority(char C){  
   if (C == '-' || C == '+')  
       return 1; 
   else if (C == '*' || C == '/')  
       return 2;  
   else if (C == '^')  
       return 3;  
   return 0;
}  

string infixToPostfix(string infix){  
   infix = '(' + infix + ')';  
   int l = infix.size();  

   stack<char> char_stack;  
   string output;  
   for (int i = 0; i < l; i++) {  
       // If the scanned character is an  
       // operand, add it to output.  
       if (isalpha(infix[i]) || isdigit(infix[i]))  
           output += infix[i];  
       // If the scanned character is an  
       // ‘(‘, push it to the stack.  
       else if (infix[i] == '(')  
           char_stack.push('(');
       // If the scanned character is an  
       // ‘)’, pop and output from the stack  
       // until an ‘(‘ is encountered.  
       else if (infix[i] == ')') {
           while (char_stack.top() != '(') {  
               output += char_stack.top();  
               char_stack.pop();  
           }  
           // Remove '(' from the stack  
           char_stack.pop();  
       }  
       // Operator found  
       else {
           if(isOperator1(char_stack.top())) {  
               while (getPriority(infix[i]) <= getPriority(char_stack.top())) { 
                   output += char_stack.top();  
                   char_stack.pop();  
               }
               // Push current Operator on stack  
               char_stack.push(infix[i]);  
           }
       }
   }
   return output;
} 
 
int main(){

    string s, str;
    
	cout << "Masukkan infix: ";
    cin >> str;
    s = infixToPostfix(str);
	int n = s.length();
    
    char char_array[n + 1];
 
    strcpy(char_array, s.c_str());
 
    for (int i = 0; i < n; i++){
    	if(char_array[i] == ' '){
    		continue;
		}else{
		
	    	if(op(char_array[i]) == true){
				if(char_array[i+1] == '-'){
					cout << " " << char_array[i] << " -1 ";
					char_array[i+1] = '*';
				}else{
					cout << " " << char_array[i] << " ";	
				}	
			}else{
			
				if(char_array[i] == '('){
	    			cout << char_array[i] << " ";
				}else if(char_array[i] == ')'){
					cout << " " << char_array[i];
				}else{
					cout << char_array[i];	
				}
			
			}
		}
	}
    
    
 
    return 0;
}
