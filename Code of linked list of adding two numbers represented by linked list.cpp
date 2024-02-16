#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->next = NULL;
    this->data = data;
  }
};
void insertathead(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode  = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }

  else{
    Node* newNode  = new Node(data);
    newNode->next = head;
    head = newNode;

  }

}
void insertattail(Node* &head,Node* &tail,int data){
if(head==NULL){
    Node* newNode  = new Node(data);
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
void reverse(Node* &head){
  if(head==NULL){
    cout<<"LL is empty: "<<endl;
    return;
  }
  else{
    Node* curr = head;
    Node* prev = NULL;
    while(curr!=NULL){
      Node* newNode = curr->next;
      curr->next = prev;
      prev = curr;
      curr = newNode;
    }
    head = prev;

    
  }
}
void addtwoll(Node* &head,Node* &head2){
  reverse(head);
  reverse(head2);

  Node* temp = head;
  Node* temp2 = head2;
  while(temp!=NULL&&temp2!=NULL){
    temp->data = temp->data+temp2->data;
    temp = temp->next;
    temp2 = temp2->next;
  }
  reverse(head);

}
void print(Node* &head){

  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }

}
int main() {
    
    Node* head = NULL;
    Node* tail = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    insertathead(head,tail,4);
    insertathead(head,tail,3);
    insertathead(head,tail,1);
    insertathead(head,tail,5);

    insertathead(head2,tail2,3);
    insertathead(head2,tail2,2);
    insertathead(head2,tail2,2);
    insertathead(head2,tail2,3);

  
    addtwoll(head,head2);
    print(head);
    
    


  return 0;
}