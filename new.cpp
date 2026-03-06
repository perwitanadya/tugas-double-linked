#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertFirst(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

void insertLast(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void insertNext(int key, int value) {
    Node* temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node dengan nilai " << key << " tidak ditemukan.\n";
        return;
    }

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    delete temp;
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = head;

    if (temp->next == NULL) {
        head = NULL;
        delete temp;
        return;
         }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void deleteByValue(int value) {
    if (head == NULL) {
        cout << "List kosong.\n";
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data tidak ditemukan.\n";
        return;
    }

    if (temp == head) {
        deleteFirst();
        return;
    }

    if (temp->next == NULL) {
        deleteLast();
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}

void display() {
    Node* temp = head;

    cout << "Isi Double Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertFirst(40);
    insertLast(50);
    insertLast(60);
    insertNext(50, 55);

    display();

    deleteFirst();
    display();

    deleteLast();
    display();

    deleteByValue(55);
    display();

    return 0;
}