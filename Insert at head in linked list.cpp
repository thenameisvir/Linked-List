#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;

  Node(){
        this->next = NULL;
  }

  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};

void insertathead(Node* &head,int data){
  if(head==NULL){
    Node* newNode = new Node(data);
    head = newNode;
  }
  else{
  Node* newNode = new Node(data);
  newNode->next = head;
  head = newNode;
  }
}
void print(Node* head){
  Node* temp = head;
  int c = 0;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
    c++;
  }
  


}
int main() {
  
 Node* first = new Node(33);
 Node* second = new Node(13);
 Node* third = new Node(23);
 Node* fourth = new Node(63);
 Node* fifth = new Node(83);

 first->next = second;  
 second->next = third;
 third->next = fourth;
 fourth->next = fifth;

 Node* head = first;
 insertathead(head,22);
 print(head);



  return 0;
}