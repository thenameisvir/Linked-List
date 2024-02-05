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
  tail = newNode;
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
Node* middle(Node* &head,Node* &tail){

  int s = 0;
  int e = getlength(head)-1;
  int pos = e/2;
  Node* temp = head;
  
    while(s<=pos){
      s++;
      temp = temp->next;
      
    }
  

  return temp;
  
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
  Node* middlenode = middle(head,tail);
  cout<<middlenode->data<<" ";
  // print(head);
  return 0;
}