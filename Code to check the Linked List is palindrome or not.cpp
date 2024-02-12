#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

Node* middle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
}

bool compare(Node* head1, Node* head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

bool isPalindrome(Node* head) {
    if (head == nullptr) {
        return true; // Empty list is considered palindrome
    }

    Node* midNode = middle(head);
    Node* head2 = midNode->next;
    midNode->next = nullptr;

    head2 = reverse(head2);

    bool result = compare(head, head2);

    // Restore the original list structure
    head2 = reverse(head2);
    midNode->next = head2;

    return result;
}

void print(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtHead(head, tail, 1);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 3);
    insertAtHead(head, tail, 2);
    insertAtHead(head, tail, 1);

    cout << "Linked List: ";
    print(head);

    if (isPalindrome(head)) {
        cout << "Linked List is a palindrome." << endl;
    } else {
        cout << "Linked List is not a palindrome." << endl;
    }

    return 0;
}
