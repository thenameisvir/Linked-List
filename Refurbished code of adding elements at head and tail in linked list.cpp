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
  }
  else{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
  }
}
void insertatTail(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }
  else{
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail=newNode;
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
  insertatHead(head,tail,4);
  insertatHead(head,tail,3);
  insertatHead(head,tail,2);
  insertatHead(head,tail,1);
  insertatTail(head,tail,5);
  insertatTail(head,tail,6);
  insertatTail(head,tail,7);
  print(head);

}