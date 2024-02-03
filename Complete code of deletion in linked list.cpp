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
void insertatHead(Node* &head,Node* &tail,int data){
if(head==NULL){
  Node* newNode = new Node(data);
  head = newNode;
  tail = newNode;
  return;
}
Node* newNode = new Node(data);
newNode->next = head;
head = newNode;

}
void insertatTail(Node* &head,Node* &tail,int data){
if(head==NULL){
  Node* newNode = new Node(data);
  head = newNode;
  tail = newNode;
  return;
}
Node* newNode = new Node(data);
tail->next = newNode;
tail = newNode;

}
int getlength(Node* &head){
Node* temp = head;
int num = 0;
while(temp!=NULL){
num++;
temp=temp->next;
}
return num+1;
}
void insetatPosition(Node* &head,Node* &tail,int data,int position){
if(head==NULL){
  Node* newNode = new Node(data);
  head = newNode;
  tail = newNode;
  return;
}
int len = getlength(head);
if(position==1){
  insertatHead(head,tail,data);
}
else if(position==len){
  insertatTail(head,tail,data);
}
else{
  Node* prev = NULL;
  Node* curr = head;
  int c = position;
  while(c>1){
    prev = curr;
    curr = curr->next;
    c--;
  }
  Node* newNode = new Node(data);
  newNode->next = curr;
  prev->next = newNode;
}

}
void deleteNode(Node* &head,Node* &tail,int position){
if(head==NULL){
  cout<<"Cannot delete because LL is empty: "<<endl;
  return;
}
if(position==1){
  Node* temp = head;
  head = head->next;
  delete temp;
  if (head == NULL) 
            tail = NULL;
        return;


}
int len2 = getlength(head)-1;
if(position==len2){
Node* prev = head;
while(prev->next != tail){
  prev = prev->next;
}
prev->next = NULL;

delete tail;

tail = prev;

}

else{
  Node* prev = NULL;
  Node* curr = head;
  int c = position;
  while(c>1){
    prev = curr;
    curr = curr->next;
    c--;
  }
  prev->next = curr->next;
  delete curr;
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
  insertatHead(head,tail,1);
  insertatHead(head,tail,3);
  insertatHead(head,tail,11);
  insertatTail(head,tail,2);
  deleteNode(head,tail,4);
  print(head);

}