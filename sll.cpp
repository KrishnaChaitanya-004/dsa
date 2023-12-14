#include <iostream>
using namespace std;

struct node {
  int data;
  node *link;
};                       

struct head {
  int count;
  node *first;
};

class SLL {
  private:
    head *headnode;
  public:
    void create() {
      headnode = new head();
      headnode->count = 0;
      headnode->first = NULL;
    }   

    bool insert(int x){
      int found;
      node *temp = new node();
      if(temp == NULL){
        return false;
      }else{
        temp->data = x;
        temp->link = NULL;
      }
      node *ppre = NULL;
      node *ploc = NULL;
      found = search(ppre,ploc,x);
      if(found) return false;
      if(ppre == NULL){
        temp->link = headnode->first;
        headnode->first = temp;
        (headnode->count)++;
        return true;
      }
      else {
        temp->link = ppre->link;
        ppre->link = temp;
        (headnode->count)++;
        return true;
      }
    }
    bool del(int x){
      node *ppre = NULL;
      node *ploc = NULL;
      int found = search(ppre,ploc,x);
      if(!found) return false;
      if(ppre == NULL){
         node*temp = headnode->first;
         cout << "\nData deleted" << temp->data;
         headnode->first = headnode->first->link;
         delete temp;
         (headnode->count)--;
         return true;
      }
       else {
        node *temp = ploc;
        cout << "\nData deleted:"<<temp->data<<endl;
        ppre->link = ploc->link;
        delete temp;
        (headnode->count)--;
         return true;
       }

    }

    bool search(node *&ppre, node *&ploc,int target) {
      ppre = NULL;
      ploc = headnode->first;
      while(ploc != NULL && (ploc->data)<target){
         ppre = ploc;
         ploc = ploc->link;
      }
      if(ploc == NULL) return false;
      else if(ploc->data == target) return true;
      else return false;
   }

   bool isfull(){
      node *temp = new node();
      if(temp == NULL) return true;
      else {
        delete temp;
        return false;
      }
  }

  bool isempty() {
     if(headnode->first == NULL) return true;
     else return false;
  }

   int returncount(){
        return (headnode->count);
    }   
    void display(){
      cout << "\nList elements";
      node *temp = headnode->first;
      while(temp!= NULL){
        cout << temp->data << " ";
        temp = temp->link;
      }
      cout << endl;
   }
   void destroy(){
      node *temp = headnode->first;
      while(headnode->first != NULL){
         temp = headnode->first;
         headnode->first = headnode->first->link;
         delete temp;
         (headnode->count)--;
      } 
      delete headnode;
      cout << "\nList destroyed" << endl;
  }
};

int main(){
   SLL s;
   int ch,x;
   bool success;
   node *ppre = NULL , *ploc = NULL;
   s.create();
   do {
     cout << "\n1 insert 2 delete 3)search 4) check full \n 5) check empty 6) getcount 7) display 8) destroy";
     cout << "\nEnter your choice: ";
     cin >> ch;
     switch(ch){
        case 1: {
          cout << "\nEnter element to insert: ";
          cin >> x;



          success = s.insert(x);
          if(success) cout <<"\nInserted successfully";
          else cout << "\nfull memory";
          break;
        }
        case 2: {
          cout << "\nEnter element to delete: ";
          cin >> x;
          success = s.del(x);
          if(success) cout <<"\ndeleted successfully";
          else cout << "\nelement does'nt exist";
          break;
        }
        case 3: {
          cout << "\nElement to be searched: ";
          cin >> x;
          success = s.search(ppre,ploc,x);
          if(success) cout <<"\nElement found";
          else cout << "\nNot found";
          break;
       }
        case 4: {
          if(s.isfull()) cout << "\nlist is full ";
          else cout << "\nlist is not full";
          break;
        }
        case 5: {
          if(s.isempty()) cout << "\nlist is empty";
          else cout << "\nlist is not empty";
          break;
        }
        case 6: {
          cout << "\ncount = "  << s.returncount();
          break;
        }
        case 7: {
           s.display(); 
           break;
        }
        case 8: {
        s.destroy();
          cout << "\nprogram now exist";
          break;
       }
     }
   }
   while(ch !=0);
   return 0;
}
