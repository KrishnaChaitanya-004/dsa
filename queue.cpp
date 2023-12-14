#include<iostream>
using namespace std;
class queue
{
  int q[20],n,f,r;
  public:
  queue()
  {
    f=-1;
    r=-1;
    cout<<"\nenter no of elements";
    cin>>n;
  }
  void enqueue();
  void dequeue();
  void display();
  void queueempty();
  void queuefull();
  void queuefront();
  void queuerear();
};
void queue::enqueue()
{
  int x;
  if(r==n-1)
  {
    cout<<"\nqueue is full";
  }
  else
  {
       cout<<"\nenter element to be inserted";
       cin>>x;
       if(f==-1)
       {
        f=0;
      }
      r=r+1;
      q[r]=x;
  }
}
void queue::dequeue()
{
  int y;
    if(f==-1&&r==-1)
  {
    cout<<"\nqueue is empty";
  }
  else
  {
    y=q[f];
    cout<<"\n"<<y<<"is deleted";
  if(f==r)
  {
    f=-1;
  }
  else
  {
    f=f+1;
  }
  }
}
void queue::display()
{
  
  if(f==-1&&r==-1)
  {
    cout<<"\nqueue is empty";
  }
  else
  {
    for(int i=f;i<r;i++)
    {
      cout<<q[i];
    }
  }
}
void queue::queueempty()
{
  if(f==-1&&r==-1)
  {
    cout<<"\nqueue is empty";
  }
  else
  {
    cout<<"\nqueue is not empty";
  }
}
void queue::queuefull()
{
  if(r=n-1)
  {
    cout<<"\nqueue is full";
  }
  else
  {
    cout<<"\nqueue is not full";
  }
}
void queue::queuefront()
{
  if(f==-1&&r==-1)
  {
    cout<<"\nqueue is empty";
  }
  else
  {
    cout<<q[f];
  }
}
void queue::queuerear()
{
  if(f==-1&&r==-1)
  {
    cout<<"\nqueue is empty";
  }
  else
  {
    cout<<q[r];
  }
}
int main()
{
  queue s1;
  int ch;
  do
  {
    cout<<"1.enquque\n2.dequeue\n3.display\n4.queue empty\n5.queue full\n6.queue front\n7.queue rear";
    cout<<"enter ur choice:\n";
    cin>>ch;
    switch(ch)
    {
      case 1:
        {
          s1.enqueue();
          break;
        }
      case 2:
      {
        s1.dequeue();
        break;
      }
    case 3:
      {
        s1.display();
        break;
      }
    case 4:
      {
        s1.queueempty();
        break;
      }
     case 5:
     {
      s1.queuefull();
      break;
     }
     case 6:
      {
        s1.queuefront();
        break;
      }
     case 7:
      {
        s1.queuerear();
        break;
      }
      default:
      {
      cout<<"bad input";
      break;
      }
    }
  }while(ch<8);
  return 0;
}
