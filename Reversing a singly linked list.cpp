#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
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
  newNode = tail;
}
}
int getlength(Node* &head){
Node* temp = head;
int c = 0;
while(temp!=NULL){
  temp = temp->next;
  c++;
}
return c;
}
void reverse(Node* &head){
if(head==NULL){
  cout<<"LL is empty, can;t reverse: "<<endl;
  return;
}
else{
  Node* prev = NULL;
  Node* curr = head;
  while(curr!=NULL){
    Node* newNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = newNode;
  }
  head = prev;
}
}
void print(Node* &head){
Node* temp = head;
while(temp!=NULL){
  cout<<temp->data<<" ";
  temp=temp->next;
}
}
int main() {
  Node* head = NULL;
  Node* tail = NULL;
  insertathead(head,tail,1);
  insertathead(head,tail,2);
  insertathead(head,tail,3);
  insertathead(head,tail,4);
  insertathead(head,tail,5);
  insertathead(head,tail,6);
  insertathead(head,tail,7);
  reverse(head);
  print(head);
  return 0;
}