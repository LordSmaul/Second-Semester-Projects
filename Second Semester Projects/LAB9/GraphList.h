#ifndef GRAPHLIST_H
#define GRAPHLIST_H

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class GraphList
{
private:
    struct listNode
    {
        int value;
        listNode *next;
    };
    listNode **headArray;
    int numVertices;
    int numEdges;

public:
    GraphList(int);
    ~GraphList();
    void addEdge(int, int);
    void printGraph();
};

GraphList::GraphList(int num)
{
    numVertices = num;
    numEdges = 0;
    headArray = new listNode *[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        headArray[i] = NULL;
    }
}

GraphList::~GraphList()
{
    for (int i = 0; i < numVertices; i++)
    {
        if (!headArray[i])
        {
            listNode *nodePtr = headArray[i];
            listNode *prev = NULL;
            while (nodePtr)
            {
                prev = nodePtr;
                nodePtr = nodePtr->next;
                delete prev;
            }
        }
    }
}

void GraphList::addEdge(int from, int to)
{
    listNode *newNode = new listNode;
    newNode->value = to;
    newNode->next = NULL;

    if (!headArray[from])
    {
        headArray[from] = newNode;
    }
    else
    {
        listNode *nodePtr = headArray[from];
        while (nodePtr->next)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }

    numEdges++;
}

void GraphList::printGraph()
{
    cout << "\n\nAdjacency List..." << endl;
    for (int i = 0; i < numVertices; i++)
    {
        listNode *nodePtr = headArray[i];
        if (nodePtr == NULL)
        {
            cout << i << "--->NULL" << endl;
        }
        else
        {
            cout << i << "--->";
            while (nodePtr)
            {
                cout << nodePtr->value << "--->";
                nodePtr = nodePtr->next;
            }
            cout << "NULL" << endl;
        }
    }
}

#endif