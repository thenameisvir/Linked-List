#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next = NULL;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertattail(Node*& head, Node*& tail, int data) {
    if (head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }
    Node* newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

Node* reverse(Node*& head) {
    if (head == NULL) {
        cout << "LL is empty: " << endl;
        return head;
    } else {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL) {
            Node* newNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = newNode;
        }
        head = prev;
        return head;
    }
}

void plus1(Node*& head) {
    head = reverse(head);

    int carry = 1;
    Node* temp = head;
    while (temp != NULL) {
        int totalSum = temp->data + carry;
        temp->data = totalSum % 10;
        carry = totalSum / 10;
        if (carry == 0) {
            break;
        }
        if (temp->next == NULL && carry != 0) {
            Node* newNode = new Node(carry);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    head = reverse(head);
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    insertathead(head, tail, 9);
    insertathead(head, tail, 5);
    insertathead(head, tail, 4);
    insertathead(head, tail, 3);
    insertathead(head, tail, 2);
    insertathead(head, tail, 9);
    reverse(head);
    plus1(head);
    print(head);

    return 0;
}
