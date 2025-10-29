
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

int countAndDeleteOccurrences(Node*& head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            count++;
        } else curr = curr->next;
    }
    return count;
}

void display(Node* head) {
    while (head) { cout << head->data << " "; head = head->next; }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(1);
    int key = 1;
    int count = countAndDeleteOccurrences(head, key);
    cout << "Count: " << count << endl << "Updated List: ";
    display(head);
}
