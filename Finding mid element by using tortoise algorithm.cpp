#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = next;
  }
};
void insertathead(Node* &head,Node* &tail,int data){
  if(head==NULL){
    Node* newNode = new Node(data);
    head=newNode;
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
    head=newNode;
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
  int num = 0;
  while(temp!=NULL){
    num++;
    temp = temp->next;
  }
  return num;
}
Node* middle(Node* &head){
if(head==NULL){
  cout<<"LL is empty: "<<endl;
  return NULL;
}
else{
  Node* slow = head;
  Node* fast = head;

  while(fast!=NULL&&fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
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
  insertathead(head,tail,5);
  insertathead(head,tail,4);
  insertathead(head,tail,3);
  insertathead(head,tail,2);
  insertathead(head,tail,1);
  Node* mid = middle(head);
  cout<<mid->data<<" ";

}