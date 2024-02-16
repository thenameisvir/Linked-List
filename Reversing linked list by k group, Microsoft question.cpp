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
Node* reversekgroup(Node* &head, int k) {
    int count = 0;
    Node* curr = head;
    Node* prev = nullptr;
    Node* nextNode = nullptr;

    // Reverse first k nodes of the linked list
    while (count < k && curr != nullptr) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }

    // If count is less than k, no need to reverse, so reverse back the first k nodes
    if (count < k) {
        curr = prev;
        prev = nullptr;
        while (curr != nullptr) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev; // Return the head of the unchanged portion of the list
    }

    // Recursively call for the rest of the list and link the new head to the current head
    if (nextNode != nullptr) {
        head->next = reversekgroup(nextNode, k);
    }

    // Return the new head of the reversed group
    return prev;
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

    insertathead(head,tail,8);
    insertathead(head,tail,7);
    insertathead(head,tail,6);
    insertathead(head,tail,5);
    insertathead(head,tail,4);
    insertathead(head,tail,3);
    insertathead(head,tail,2);
    insertathead(head,tail,1);
    Node* r = reversekgroup(head,2);

  
    
    print(r);
    
    


  return 0;
}