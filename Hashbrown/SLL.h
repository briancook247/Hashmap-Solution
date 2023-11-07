/*
* Brian Cook
* CST-201 1pm
* 9/27/2022
* My Own Work
*/

#include <iostream>
using namespace std;
// Create a node type to use for SLL
struct node {
    int data;
    node* next;
};

class SLL {
public:
    node* head = NULL;

public:
    // Default constructor for SLL
    SLL() {};
    // Construct an SLL by passing data to head node  O(1)
    SLL(int data) {
        struct node* newNode = new node;
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;

    }
    // Copy Constructor for a SLL   O(n)
    SLL(SLL& oldSLL) {
        struct node* temp;
        head = oldSLL.head;
        temp = oldSLL.head;

        while (temp != NULL) {
            struct node* newNode = new node;
            newNode->data = temp->data;
            newNode->next = temp->next;
            temp = temp->next;
        }
    }
    // Time complexity is O(1)
    void front() {
        cout << "\nFirst element is " << head->data << endl;
    }
    // Time complexity is O(n)
    void back() {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        cout << "\nLast element is " << temp->data << endl;
    }
    // Time complexity is O(1)
    void pop_front() {
        head = head->next;
    }
    // Time complexity is O(n)
    void pop_back() {
        struct node* temp = head;
        struct node* previous = new node;

        while (temp->next != NULL) {
            previous = temp;
            temp = temp->next;
        }
        previous->next = temp->next;
        delete(temp);

    }
    // Time complexity is O(1)
    bool isEmpty() {
        if (head != NULL) {
            return false;
        }
        else if (head == NULL)
            return true;
    }
    // Time complexity is O(n)
    int size() {
        int size = 0;
        struct node* temp;
        temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }
    // Time complexity is O(1)
    void insertFront(int newData) {
        struct node* newNode = new node;
        newNode->data = newData;
        newNode->next = head;
        head = newNode;
    }
    // Time complexity is O(n)
    void insertEnd(int newData) {
        struct node* newNode = new node;
        struct node* temp = head;

        newNode->data = newData;
        newNode->next = NULL;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // Insert data to a certain index
    // Time complexity is O(n)
    void insertPos(int pos, int newData) {
        struct node* newNode = new node;
        struct node* temp = head;
        struct node* previous = new node;
        int position = pos;
        newNode->data = newData;
        for (int i = 1; i < position; i++) {
            previous = temp;
            temp = temp->next;
        }
        previous->next = newNode;
        newNode->next = temp;
    }
    // Insert data in ascending order
    // Time complexity is O(n)
    void insert(int val) {
        struct node* newNode = new node;
        newNode->data = val;
        if (head->data >= newNode->data || head->data == NULL) {
            newNode->next = head;
            head = newNode;
        }
        else if (head->data < newNode->data) {
            struct node* prev = new node;
            struct node* temp = head;

            while (temp != NULL && temp->data < val) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = newNode;
            newNode->next = temp;
        }
    }
    // Merges one SLL with another SLL maintaining ascending order
    // Time complexity is O(n+m)
    void merge(SLL sll) {
        struct node* temp = sll.head;
        while (temp != NULL) {
            insert(temp->data);
            temp = temp->next;
        }
    }
    // Time complexity is O(n)
    void deleteNode(int newData) {
        struct node* temp = head;

        struct node* previous = new node;
        if (temp != NULL && temp->data == newData) {
            head = temp->next;
            delete(temp);
        }
        while (temp != NULL && temp->data != newData) {
            previous = temp;
            temp = temp->next;
        }
        previous->next = temp->next;
        delete(temp);
    }
    // Time complexity is O(n)
    void display() {
        struct node* temp;
        temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Prints out reversed version of list
    // Time complexity is O(n)
    SLL reverse() {
        struct node* temp;
        temp = head;
        SLL newList(temp->data);
        temp = temp->next;
        while (temp != NULL) {
            newList.insertFront(temp->data);
            temp = temp->next;
        }
        return newList;
    }
};