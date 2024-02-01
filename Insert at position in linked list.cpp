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
void insertatposition(Node* &head,Node* &tail,int data,int position){
if(head==NULL){
  Node* newNode = new Node(data);
  head = newNode;
  tail = newNode;
  return;
}
if(position<=1){
  insertathead(head,tail,data);
}
int length = getlength(head)+1;
if(position==length||position>length){
  insertattail(head,tail,data);
}

else{
  Node* newNode = new Node(data);
  Node* prev = NULL;
  Node* curr = head;
  while(position!=1){
    prev = curr;
    curr = curr->next;
    position--;
  }
  prev->next = newNode;
  newNode->next = curr;
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
  insertattail(head,tail,1);
  insertathead(head,tail,2);
  insertatposition(head,tail,0,2);
  print(head);
  return 0;
}