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
  Node* newNode = new Node(data);
  newNode->next = head;
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
  tail = newNode;
}

Node* getstartingpointofLoop(Node* &head){
  Node* slow = head;
  Node* fast = head;
  while(fast!=NULL&&fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;

    if(fast==slow){
      break;
    }
  }

  slow = head;
  while(slow!=fast){
    slow = slow->next;
    fast = fast->next;
  }

  return slow;

}
int main() {
  Node* head = NULL;
  Node* tail = NULL;
  
  // Insert nodes to create a linked list with a loop
  head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  
  // Create a loop from the last node to the second node
  head->next->next->next->next->next = head->next;

  Node* start = getstartingpointofLoop(head);
  cout<<start->data<<" ";

  

  return 0;
}
