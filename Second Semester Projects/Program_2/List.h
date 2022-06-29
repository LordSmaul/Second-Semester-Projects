/*
    File Name: List.h
    Author: LordSmaul
    Date: 3/08/2022
    Purpose: To create a doubly linked list of US counties and Merge Sort them in descending order by population
*/

#ifndef LIST_H
#define LIST_H

#include "County.h"

template <typename T>
class List
{
public:
    List();                   // Constructor
    ~List();                  // Destructor
    void print();             // prints out values of the List
    void append(T newCounty); // appends new ListNode to the List
    void mergesort();         // Sorts List using merge sort algorithm

private:
    struct ListNode
    {
        T county;
        ListNode *next;
        ListNode *prev;
    };
    ListNode *head;
    ListNode *tail;

    void print(ListNode *head);                                                   // Prints out all values from any starting ListNode
    int getLength(ListNode *value);                                               // Gets length of partition (used in split() function)
    typename List<T>::ListNode *mergesort(ListNode *first, ListNode *last);       // Recursive serge sort function
    typename List<T>::ListNode *merge(ListNode *firstLeft, ListNode *firstRight); // Recursive merge function
    typename List<T>::ListNode *split(ListNode *first, ListNode *last);           // Splits List in half
};

// List Constructer: sets head and tail pointers to NULL
template <typename T>
List<T>::List()
{
    head = NULL;
    tail = NULL;
}

// List Destructor: Deletes every element in the List
template <typename T>
List<T>::~List()
{
    ListNode *nodePtr = head;
    ListNode *next = NULL;

    while (nodePtr)
    {
        next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
}

// Public Function: prints all values in the List, starting from any specified point
// Uses Private Function print() to print values
template <typename T>
void List<T>::print() { print(head); }

// Private Funtion: prints out all values in the List
// Starts at the parameter pointer and iterates through each List element
// Uses overloaded "<<" operator to print out each County object in a readable format
template <typename T>
void List<T>::print(ListNode *head)
{
    // If no elements exist in the List
    if (!head)
    {
        cout << "There are no elements to display.";
    }
    else
    {
        ListNode *nodePtr = head;
        while (nodePtr)
        {
            cout << *(nodePtr->county) << endl;
            nodePtr = nodePtr->next;
        }
    }
}

// Public Function: assigns a new ListNode with newly created County value and appends it to the end of the List
template <typename T>
void List<T>::append(T newCounty)
{
    ListNode *newNode = new ListNode;
    newNode->county = newCounty;

    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Private Function: gets length of the partition
// I made this function to account for issues with traversing through the partition in the split() function,
// as there was an issue with recursive partitioning when the partition contained an odd number of elements
template <typename T>
int List<T>::getLength(ListNode *value)
{
    int count = 0;
    ListNode *nodePtr = value;
    while (nodePtr)
    {
        count++;
        nodePtr = nodePtr->next;
    }
    return count;
}

// Public Function: splits the partition in half, returning the pointer after the middle pointer
// Severs the connection between the two partitions to allow for merge sorting/partitioning
template <typename T>
typename List<T>::ListNode *List<T>::split(ListNode *first, ListNode *last)
{
    ListNode *nodePtr = first;
    int length = getLength(first); // Gets length of partition

    // Traverses through partition until it finds a middle element
    // Accounts for the partition holding an even or odd number of elements
    while ((length % 2 == 0 && nodePtr->next != last) || (length % 2 != 0 && nodePtr != last))
    {
        nodePtr = nodePtr->next;
        last = last->prev;
    }

    ListNode *temp = nodePtr->next; // Sets return pointer to value after the middle pointer
    nodePtr->next = NULL;           // Severs the 'next' pointer connection between the two partitions
    return temp;
}

// Public Function: Sorts the List using merge sort algorithm
// Uses Private Function mergesort() recursively sort the List
// Sets new head and tail pointers of List
template <typename T>
void List<T>::mergesort()
{
    ListNode *nodePtr;

    head = mergesort(head, tail); // mergesort() returns the head value of the List

    nodePtr = head;

    // Traverses through the List to find the tail
    while (nodePtr)
    {
        nodePtr = nodePtr->next;
    }

    tail = nodePtr;
}

// Private Function: Recursively merge sorts each partition, returning the value of the merged partitions
// Returns a pointer to the beginning of the newly sorted List
template <typename T>
typename List<T>::ListNode *List<T>::mergesort(ListNode *first, ListNode *last)
{
    // If one or no elements remain
    if (!first || !first->next)
    {
        return first;
    }
    else
    {
        ListNode *leftFirst = first;               // Sets pointer to beginning of left partition
        ListNode *rightFirst = split(first, last); // Sets pointer to beginning of right partition

        leftFirst = mergesort(first, rightFirst->prev); // Recursively sorts left partition
        rightFirst = mergesort(rightFirst, last);       // Recursively sorts right partition
        return merge(leftFirst, rightFirst);            // Recursively merges List and returns pointer to beginning of newly sorted List
    }
}

// Private Function: Merges the partitions, which are sorted in descending order based on County population
template <typename T>
typename List<T>::ListNode *List<T>::merge(ListNode *firstLeft, ListNode *firstRight)
{
    // If left partition is empty
    if (!firstLeft)
    {
        return firstRight;
    }
    // If right partition is empty
    if (!firstRight)
    {
        return firstLeft;
    }

    // Sorts County values of each ListNode in descending order based on County population
    if (firstLeft->county->getPopulation() >= firstRight->county->getPopulation())
    {
        firstLeft->next = merge(firstLeft->next, firstRight);
        firstLeft->next->prev = firstLeft;
        firstLeft->prev = NULL;
        return firstLeft;
    }
    else
    {
        firstRight->next = merge(firstLeft, firstRight->next);
        firstRight->next->prev = firstRight;
        firstRight->prev = NULL;
        return firstRight;
    }
}

#endif