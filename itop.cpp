#include <iostream>
#include <stack>
using namespace std;

int priority(char a){
   if(a == '+' || a == '-') return 1;
   if(a == '*' || a == '/') return 2;
   if(a == '^') return 3;
   else return 0;
}

void convert(string infix){
  string postfix = "";
  stack <int>s;
  int i = 0;
  while(infix[i] != '\0')
	{
     if(infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z'){
        postfix += infix[i];
        i++;
     }
     else if(infix[i] == '(')
	{
         s.push(infix[i]);
         i++;
     }
     else if(infix[i] == ')')
	{
        while(s.top() != '(')
	{
           postfix += s.top();
           s.pop();
        }
        s.pop();
        i++;
     }
     else {
       while(!s.empty() && priority(infix[i]) <= priority(s.top())) {
          postfix += s.top();
          s.pop();
       }
       s.push(infix[i]);
       i++;
     }
  }
  while(!s.empty()){
    postfix += s.top();
    s.pop();
  }
  cout << "postfix = " << postfix << "\n";
}

int main(){
  string in;
  cin >> in;
  convert(in);
  return 0; 
}

