#include<iostream>
#include<algorithm>
using namespace std;
class Node{
public:
int data;
Node* next;
Node* prev;

Node(int data){
  this->data = data;
  this->next = NULL;
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
Node* newNode = new Node(data);
newNode->next = head;
head->prev = newNode;
head = newNode;
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
newNode->prev = tail;
tail = newNode;
}
int getlength(Node* &head){
  int num = 0;
  Node* temp = head;
  while(temp!=NULL){
    num++;
    temp=temp->next;
  }
  return num;
}
void reverse(Node* &head,Node* &tail){
int s = 0;
int e = getlength(head)-1;
if(head==NULL){
  cout<<"Cannot insert because LL is empty: "<<endl;
}
else{
  Node* first = head;
  Node* last = tail;
  while(s<e){
    s++;
    e--;
    swap(first->data,last->data);
    first = first->next;
    last = last->prev;
  }
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
  insertathead(head,tail,1);
  insertathead(head,tail,2);
  insertathead(head,tail,3);
  insertathead(head,tail,4);
  insertathead(head,tail,5);
  insertathead(head,tail,6);
  reverse(head,tail);
  print(head);

}
