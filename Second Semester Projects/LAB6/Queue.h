#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue
{
private:
    struct queueNode
    {
        string riderName;
        queueNode *next;
    };
    queueNode *head;
    queueNode *tail;

public:
    Queue();
    ~Queue();
    void enqueue(string value);
    void dequeue(string &value);
    bool isEmpty() const;
};

Queue::Queue() // Queue Constructor
{
    head = NULL;
    tail = NULL;
}

Queue::~Queue() // Queue Destructor
{
    queueNode *nodePtr = head;
    while (nodePtr)
    {
        queueNode *temp = nodePtr;
        cout << "Oh shoot, I am sorry, our park is closed so " << temp->riderName << " will not get to ride today." << endl;
        nodePtr = nodePtr->next;
        delete temp;
    }
}

bool Queue::isEmpty() const // Checks if Queue is empty
{
    return (!head) ? true : false;
}

void Queue::enqueue(string value) // appends rider to the end of the Queue
{
    queueNode *newNode = new queueNode;
    newNode->riderName = value;

    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void Queue::dequeue(string &value) // Removes rider from the front of the Queue
{
    queueNode *nodePtr;

    if (!isEmpty())
    {
        nodePtr = head;
        head = head->next;
        value = nodePtr->riderName;
        delete nodePtr;
    }
}

#endif