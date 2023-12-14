//Binary Search Tree
#include<iostream>
using namespace std;

struct node
{
 int data;
 node* left;
 node* right;
};


node* insert(node* root,node* temp)
{
 if(root==NULL)
 {
  return temp;
 }
 else if(temp->data<root->data)
 {
  root->left=insert(root->left,temp);
 }
 else if(temp->data>root->data)
 {
  root->right=insert(root->right,temp);
 }
 return root;
}

node* find_smallest(node* root)
{
 if(root->left==NULL)
  return root;
 else
  return find_smallest(root->left);
}

node* find_largest(node* root)
{
 if(root->right==NULL)
  return root;
 else
  return find_largest(root->right);
}

node* del(node* root,int key)
{
 if(root==NULL)
  return NULL;
 else if(root->data<key)
  root->right=del(root->right,key);
 else if(root->data>key)
  root->left=del(root->left,key); 
 else
 {
  if(root->right==NULL)
  {
   node* temp=root->left;
   delete root;
   return temp;
  }  
  else if(root->left==NULL)
  {
   node* temp=root->right;
   delete root;
   return temp;
  }  
  else
  {
   node* largest=find_largest(root->left);
   cout<<"Largest :"<<largest->data;
   cout<<"Largest moved to"<<root->data;
   root->data=largest->data;
   root->left=del(root->left,largest->data);
  }
 }
 return root;
}

void preorder(node* root)
{
 if(root!=NULL)
 {
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
 }
}

void inorder(node* root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
 }
}

void postorder(node* root)
{
 if(root!=NULL)
 {
  postorder(root->left);
  postorder(root->right);
  cout<<root->data<<" ";
 }
}

bool search(node* root,int key)
{
 if(root==NULL)
  return false;
 else if(root->data<key)
  return search(root->left,key);
 else if(root->data>key)
  return search(root->right,key);
 else
  return true;
}

int main()
{
 node *root=NULL,*l=NULL,*s=NULL,*temp=NULL;;
 int ch,x,y;
 cout<<"1.Insert\n2.Delete\n3.Search\n4.Find largest\n5.Find smallest\n6.Preorder\n7.Inorder\n8.Postorder";
 do
 {
  cout<<"\nEnter choice:";
  cin>>ch;
  switch(ch)
  {
   case 1:
   cout<<"\nEnter insert value:";
   cin>>x;
   temp=new node;
   temp->data=x;
   temp->left=temp->right=NULL;
   cout<<"\nNode created!";
   root=insert(root,temp);
   break;

   case 2:
   cout<<"\nEnter delete value:";
   cin>>y;
   if(!search(root,x))
    cout<<"\nElement does not exist";
   else
   {
    root=del(root,x);
    cout<<"\nElement deleted";
   }
   break;

   case 3:
   cout<<"\nEnter search value:";
   cin>>x;
   if(search(root,x))
    cout<<"\nElement found";
   else
    cout<<"\nElement not found";
   break;

   case 4:
   s=find_smallest(root);
   cout<<"\nSmallest = "<<s->data;
   break;

   case 5:
   l=find_largest(root);
   cout<<"\nLargest = "<<l->data;
   break;

   case 6:
   preorder(root);
   break;

   case 7:
   inorder(root);
   break;

   case 8:
   postorder(root);
   break;
  }
 }while(ch<9);
 return 0;
}



























 
  
 























































