/*
* Brian Cook
* CST-201 1pm
* Michael Sarlo
* 11/19/2022
* My Own Work
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int SIZE = 11;
const int HASH = 11;
int numInspected = 0;

struct node {
    string data;
    node* next;
};

struct node** bucketList = new node*[SIZE];

// O(n) 
// after initializing the bucketList, we set all of the pointers next = NULL and data = NULL, that way we can check for a next=null 
void initList() {
    struct node* temp = new node;
    temp->next = NULL;
    temp->data = "";
    for (int i = 0; i < SIZE; i++) {
     bucketList[i] = temp;
    }
}

// O(n) Hashing function
int hashItUp(string key) {
    int total = 0;
    for (int i = 0; i < key.length(); i++) {
        // Rolling through the input letter by letter to make our hash
        key[i] = key[i] + 3;
        total += (int)key[i];
    }
    return total;
}

// O(1), Hashes our data and sets it as first position in bucketList hash index
void insert(string newData) {
    struct node* newNode = new node;
    newNode->data = newData;
    // Insert new node at front & tie to previous first item of bucket
    newNode->next = bucketList[hashItUp(newData) % HASH];
    bucketList[hashItUp(newData) % HASH] = newNode;
}

// O(n+k), displays all n data in the table
void display() {
    struct node* temp = new node;
    for (int i = 0; i < SIZE; i++) {
        temp = bucketList[i];
        // We use temp->next because there will always be a non-null node taking up the empty spot, since we 
        // initialized the global array with node pointers... it will be non null so we get the next over
        if (temp->next == NULL) {
            continue;
        }
        while (temp->next != NULL) {
            // Traverse bucket
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
}

// O(n)
bool find(string key) {
    struct node* temp = new node;
    // Find the index of the bucket we need to look through
    int hashKey = hashItUp(key) % HASH;
    temp = bucketList[hashKey];

    if (temp->next == NULL) {
        cout << "\ndata not found";
        return false;
    }
    else if (temp->data == key) {
        cout << "\n" << key << " found at hashIndex - " << hashKey << " after looking at " << numInspected << " elements";
        return true;
    }
    else {
        // Traverse bucket until we find the right data item
        while (temp->next != NULL) {
            if (temp->data == key) {
                cout << "\n" << key << " found at hashIndex - " << hashKey << " after looking at " << numInspected << " elements";
                numInspected = 0;
                return true;
            }
            numInspected += 1;
            temp = temp->next;
        }
    }
    cout << "\nA problem occured. You either typed part of a word or an invalid input. Try again.";
    return false;
}


int main() {

    initList();

    ifstream dataIn("DataIn.txt");
    if (!dataIn) {
        cout << "File not found";
        exit(10);
    }
    string str;
    while (dataIn >> str) {
        cout << str << endl;
        insert(str);
    }

    insert("cow");
    insert("lama");

    cout << "\n\nDisplaying table:\n";
    display();

    string input;
    cout << "\n------------------------\nSearch for a word in the table. or q to quit:\n";
    while(cin >> input){
        if (input == "q") {
            break;
        }
        find(input);
        cout << "\n------------------------\nSearch for a word in the table. or q to quit:\n";
    }
}