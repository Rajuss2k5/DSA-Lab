
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next, *prev;
    Node(int val) { data = val; next = prev = NULL; }
};

class CircularLinkedList {
public:
    Node* head = NULL;

    void insertAnywhere(int val, int key = -1, int position = 0) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; newNode->next = head; return; }
        if (position == 1) {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != head && temp->data != key) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;
        Node* curr = head;
        Node* prev = NULL;
        do {
            if (curr->data == key) {
                if (curr == head) {
                    Node* temp = head;
                    while (temp->next != head) temp = temp->next;
                    if (head == head->next) { delete head; head = NULL; return; }
                    temp->next = head->next;
                    head = head->next;
                } else prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void search(int key) {
        if (!head) { cout << "Empty\n"; return; }
        Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == key) { cout << "Found at position: " << pos << endl; return; }
            temp = temp->next;
            pos++;
        } while (temp != head);
        cout << "Not found\n";
    }
};

class DoublyLinkedList {
public:
    Node* head = NULL;

    void insertAnywhere(int val, int key = -1, int pos = 0) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        if (pos == 1) {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->data != key) temp = temp->next;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;
        Node* temp = head;
        if (temp->data == key) {
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            return;
        }
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        if (temp->next) temp->next->prev = temp->prev;
        if (temp->prev) temp->prev->next = temp->next;
        delete temp;
    }

    void search(int key) {
        Node* temp = head; int pos = 1;
        while (temp) {
            if (temp->data == key) { cout << "Found at position " << pos << endl; return; }
            temp = temp->next; pos++;
        }
        cout << "Not found\n";
    }
};

int main() {
    CircularLinkedList cll;
    DoublyLinkedList dll;
    cout << "Circular and Doubly Linked List Operations Implemented.\n";
}
