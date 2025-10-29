
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data; Node* next;
    Node(int val) { data = val; next = NULL; }
};

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head) temp = temp->next;
    return (temp == head);
}

int main() {
    Node* head = new Node(2);
    Node* n1 = new Node(4);
    Node* n2 = new Node(6);
    Node* n3 = new Node(7);
    Node* n4 = new Node(5);
    head->next = n1; n1->next = n2; n2->next = n3; n3->next = n4; n4->next = head;
    cout << (isCircular(head) ? "True" : "False");
}

