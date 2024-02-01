#include<iostream>
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
Node* newNode = new Node(data);
tail->next = newNode;
newNode = tail;
}
int getlength(Node* &head){
Node* temp = head;
int num = 0;
while(temp!=NULL){
  num++;
  temp = temp->next;
}
return num+1;
}
void insertatposition(Node* &head,Node* &tail,int data,int position){
if(head==NULL){
  Node* newNode = new Node(data);
  head = newNode;
  tail = newNode;
  return;
}
int length = getlength(head);
if(position==1){
  insertathead(head,tail,data);
}
if(position==length){
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
  newNode->next = curr;
  prev->next = newNode;
}
}
void print(Node* &head){
Node* temp = head;
while(temp!=NULL){
  cout<<temp->data<<" ";
  temp = temp->next;
}
}
int main(){
  Node* head = NULL;
  Node* tail = NULL;
  insertatposition(head,tail,11,1);
  insertattail(head,tail,1);
  insertathead(head,tail,0);
  insertathead(head,tail,0);
  insertathead(head,tail,0);
  insertathead(head,tail,0);
  insertatposition(head,tail,11,3);
  print(head);

}