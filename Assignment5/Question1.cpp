
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

class LinkedList {
public:
    Node* head;
    LinkedList() { head = NULL; }

    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAfterValue(int val, int key) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertBeforeValue(int val, int key) {
        if (!head) return;
        if (head->data == key) { insertAtBeginning(val); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) return;
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;
        if (!head->next) { delete head; head = NULL; return; }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = NULL;
    }

    void deleteValue(int key) {
        if (!head) return;
        if (head->data == key) { deleteAtBeginning(); return; }
        Node* temp = head;
        while (temp->next && temp->next->data != key) temp = temp->next;
        if (!temp->next) return;
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
    }

    void search(int key) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == key) { cout << "Node found at position: " << pos << endl; return; }
            temp = temp->next;
            pos++;
        }
        cout << "Node not found" << endl;
    }

    void display() {
        Node* temp = head;
        while (temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, key;
    do {
        cout << "\n1.Insert at Beginning\n2.Insert at End\n3.Insert Before Value\n4.Insert After Value\n5.Delete from Beginning\n6.Delete from End\n7.Delete Specific Node\n8.Search\n9.Display\n10.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> val; list.insertAtBeginning(val); break;
            case 2: cin >> val; list.insertAtEnd(val); break;
            case 3: cin >> val >> key; list.insertBeforeValue(val, key); break;
            case 4: cin >> val >> key; list.insertAfterValue(val, key); break;
            case 5: list.deleteAtBeginning(); break;
            case 6: list.deleteAtEnd(); break;
            case 7: cin >> key; list.deleteValue(key); break;
            case 8: cin >> key; list.search(key); break;
            case 9: list.display(); break;
        }
    } while (choice != 10);
}
