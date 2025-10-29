#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data; Node* next; Node* prev;
    Node(int val) { data = val; next = prev = NULL; }
};

int sizeDoubly(Node* head) {
    int count = 0;
    while (head) { count++; head = head->next; }
    return count;
}

int sizeCircular(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do { count++; temp = temp->next; } while (temp != head);
    return count;
}

int main() {
    Node* d1 = new Node(10);
    d1->next = new Node(20);
    d1->next->next = new Node(30);
    cout << "Size of Doubly Linked List: " << sizeDoubly(d1) << endl;

    Node* c1 = new Node(5);
    Node* c2 = new Node(15);
    Node* c3 = new Node(25);
    c1->next = c2; c2->next = c3; c3->next = c1;
    cout << "Size of Circular Linked List: " << sizeCircular(c1) << endl;
}
