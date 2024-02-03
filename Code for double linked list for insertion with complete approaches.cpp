#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node* prev;

  Node(int data){
    this->next = NULL;
    this->data = data;
    this->prev = NULL;
  }
};
void insertathead(Node* &head,Node* &tail,int data){
if(head==NULL){
  Node* newNode = new Node(data);
  head = newNode;
  tail = newNode;
  return;
}
else{
  Node* newNode = new Node(data);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}
}
void insertattail(Node* &head,Node* &tail,int data){
  if(head==NULL){
  Node* newNode = new Node(data);
  head = newNode;
  tail = newNode;
  return;
  }
  else{
    Node* newNode = new Node(data);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}
int getlength(Node* &head){
  int num = 0;
  Node* temp = head;
  while(temp!=NULL){
    num++;
    temp = temp->next;
  }
  return num;
}
void insertatposition(Node* &head,Node* &tail,int data,int position){
  if(head==NULL){
  Node* newNode = new Node(data);
  head = newNode;
  tail = newNode;
  
  }
  int length = getlength(head);
   if(position==1){
    insertathead(head,tail,data);
  }
  else if(position==length+1){
    insertattail(head,tail,data);
  }
  else{
    int c = 1;
    Node* curr = head;
    Node* null = NULL;
    while(c<position){
      null = curr;
      curr = curr->next;
      c++;
    }

    Node* newNode = new Node(data);
    null->next = newNode;
    newNode->prev = null;
    newNode->next = curr;
    curr->prev = newNode;


  }
}
void print(Node* &head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }

  
}
int main(){
  Node* head = NULL;
  Node* tail = NULL;
  insertathead(head,tail,1);
  insertattail(head,tail,2);
  insertattail(head,tail,3);
  insertattail(head,tail,4);
  insertattail(head,tail,5);
  insertattail(head,tail,6);
  insertattail(head,tail,7);
  insertatposition(head,tail,8,4);
  print(head);
}