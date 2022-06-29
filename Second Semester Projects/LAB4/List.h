#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Class Definition
class List
{
public:
    List();                    // List Constructor
    ~List();                   // List Destructor
    void appendNode(string s); // Appends node to the end of the List
    void insertNode(string s); // Inserts node based on alphabetical order of the value
    void deleteNode(string s); // Deletes specified node from List
    void displayList() const;  // Displays values of the List
private:
    struct ListNode
    {
        string value;
        ListNode *next;
    };
    ListNode *head;
    ListNode *tail;
};

// Function Definitions
List::List()
{
    head = NULL;
    tail = NULL;

    cout << "The linked list has been created." << endl;
}

List::~List()
{
    ListNode *nodePtr = head;
    ListNode *next = NULL;
    while (nodePtr)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
    cout << "\nAll list nodes have been removed." << endl;
}

// Displays all elements of the List
void List::displayList() const
{
    if (!head)
    {
        cout << "\nThere are no more elements to be printed" << endl;
    }
    else
    {
        ListNode *nodePtr = head;
        while (nodePtr)
        {
            cout << nodePtr->value << endl;
            nodePtr = nodePtr->next;
        }
    }
}

// Adds a ListNode to the end of the List
void List::appendNode(string s)
{
    ListNode *newNode = new ListNode;
    newNode->value = s;
    newNode->next = NULL;

    if (!head) // If List is empty
    {
        head = newNode;
        tail = newNode;
    }
    else // Appends element to the end of the List
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Inserts a ListNode alphabetically into the List based on the value of the input string
void List::insertNode(string s)
{
    ListNode *newNode = new ListNode;
    newNode->value = s;
    newNode->next = NULL;

    if (!head) // If List is empty
    {
        head = newNode;
        tail = newNode;
    }
    else // Adds element alphabetically based on value
    {
        ListNode *nodePtr = head; // Used to traverse through the List
        while (nodePtr && newNode->value > nodePtr->next->value)
        {
            nodePtr = nodePtr->next;
        }
        newNode->next = nodePtr->next;
        nodePtr->next = newNode;
    }
}

// Deletes a specified node from the List
void List::deleteNode(string s)
{
    ListNode *nodePtr = head;  // Used to traverse through ListNode
    ListNode *prevNode = NULL; // Used to keep track of previous ListNode
    while (nodePtr && nodePtr->value != s)
    {
        prevNode = nodePtr;
        nodePtr = nodePtr->next;
    }
    prevNode->next = nodePtr->next;
    delete nodePtr;
}

#endif