#ifndef DYNSTACK_H
#define DYNSTACK_H

#include "InvItem.h"
using namespace std;

template <class T>
class DynStack
{
private:
    struct ListNode
    {
        T item;
        ListNode *next;
    };
    ListNode *top;

public:
    DynStack();
    bool isEmpty() const;
    void push(T item);
    void pop(T& item);
};

template <class T>
DynStack<T>::DynStack()
{
    top = NULL;
}

template <class T>
bool DynStack<T>::isEmpty() const
{
    return (!top) ? true : false;
}

template <class T>
void DynStack<T>::push(T item)
{
    ListNode *newNode = new ListNode;
    newNode->item = item;
    
    newNode->next = top;
    top = newNode;
}

template <class T>
void DynStack<T>::pop(T& item)
{
    if (!isEmpty())
    {
        ListNode *temp; // Used for referencing obsolete top variable
        temp = top;

        top = top->next; // Sets top variable to the next available value
        item = temp->item; // Sets referenced item to the item of temp

        delete temp; // Deletes old top value
    }
}

#endif