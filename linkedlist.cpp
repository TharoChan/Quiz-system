#include <iostream>

using namespace std;

struct Node {
    int Value;
    Node *Next;
};

struct List {
    Node *head, *tail;
    int n;
};

List* crateEmptyList () {
    List *L1;
    L1 = new List;

    L1 -> n = 0;
    L1 -> head = NULL;
    L1 -> tail = NULL;

    return L1;
}

void printList(Node*n) {
    while (n != NULL) {
      cout<< n->Value << endl;
      n = n->Next;
    }
}

void insertAtTheFront(Node **head, int newValue) {

}

int main () {
/*
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->Value = 1;
    head->Next = second;
    second->Value = 2;
    second->Next = third;
    third->Value = 3;
    third->Next = NULL;

    printList(head);
*/

    return 0;
}
