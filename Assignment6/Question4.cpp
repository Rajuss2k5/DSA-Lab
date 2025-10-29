
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char data; Node* next; Node* prev;
    Node(char val) { data = val; next = prev = NULL; }
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    while (head != tail && tail->next != head) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* head = new Node('r');
    head->next = new Node('a'); head->next->prev = head;
    head->next->next = new Node('d'); head->next->next->prev = head->next;
    head->next->next->next = new Node('a'); head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node('r'); head->next->next->next->next->prev = head->next->next->next;
    cout << (isPalindrome(head) ? "True" : "False");
}

