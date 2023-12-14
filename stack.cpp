#include<iostream>
using namespace std;
class stack
{
  int s[20],top,n;
  public:
    stack()
    {
      top=-1;
      cout<<"enter size of stack";
      cin>>n;
    }
    void push();
    void pop();
    void display();
    void isempty();
    void isfull();
    void stacktop();
};
void stack::push()
{
int x;
if(top==-1)
  cout<<"stack is full";
else
 {
  cout<<"enter element";
  cin>>x;
  top=top+1;
  s[top]=x;
 }
}
void stack::pop()
{
  int y;
  if(top==-1)
    cout<<"stack is empty";
  else 
  {
    y=s[top];
    top=top-1;
    cout<<y<<"is deleted";
  }
}
void stack::display()
{
  if(top==-1)
    cout<<"stck is empty";
 else
 for(int i=0;i<=top;i++)
 {
  cout<<s[i];
 }
}
void stack::isempty()
{
  if(top==-1)
    cout<<"stack is empty";
  else
    cout<<"stack is not empty";
}
void stack::isfull()
{
  if(top==n-1)
    cout<<"stack is full";
  else
    cout<<"stack is not full";
}
void stack::stacktop()
{
  if(top==-1)
    cout<<"stcak is empty";
  else
  cout<<s[top];
}
int main()
{
  stack s1;
  int ch;
  do
  {
    cout<<"1.push\n2.pop\n3.display\n4.isempty\n5.isfull\n6.stack top";
    cout<<"enter ur choice:\n";
    cin>>ch;
    switch(ch)
    {
      case 1:
        {
          s1.push();
          break;
        }
      case 2:
      {
        s1.pop();
        break;
      }
    case 3:
      {
        s1.display();
        break;
      }
    case 4:
      {
        s1.isempty();
        break;
      }
     case 5:
     {
      s1.isfull();
      break;
     }
     case 6:
      {
        s1.stacktop();
        break;
      }
      default:
      {
      cout<<"bad input";
      break;
      }
    }
  }while(ch<7);
  return 0;
}

    
    
    
    
    
    
    
    
    
    
    
