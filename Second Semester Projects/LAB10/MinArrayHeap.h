#ifndef MINARRAYHEAP_H
#define MINARRAYHEAP_H

#include <iostream>
#include <bits/stdc++.h>
#include "Creature.h"

class MinArrayHeap
{
private:
    Creature *heapArray;
    int capacity;
    int heap_size;
    void swap(Creature *x, Creature *y)
    {
        Creature temp = *x;
        *x = *y;
        *y = temp;
    }
    int parent(int i) { return (1 - 1) / 2; }
    int left(int i) { return (2 * i) + 1; }
    int right(int i) { return (2 * i) + 2; }

public:
    MinArrayHeap(int);
    ~MinArrayHeap();
    Creature *peek();
    void insert(Creature *);
    void resizeArray();
    void minHeapify(int);
    void display();
    void saveToFile();
    int getNumberOfNodes();
    int getHeight();
    bool IsEmpty();
    bool remove(Creature &);
};

MinArrayHeap::MinArrayHeap(int capacity)
{
    this->capacity = capacity;
    heap_size = 0;
    heapArray = new Creature[capacity];
}

MinArrayHeap::~MinArrayHeap()
{
    delete[] heapArray;
}

Creature *MinArrayHeap::peek()
{
    return (heapArray + 0);
}

bool MinArrayHeap::remove(Creature &creature)
{
    if (heap_size == 0)
    {
        return false;
    }

    creature = heapArray[0];
    heapArray[0] = heapArray[heap_size - 1];
    heap_size--;
    minHeapify(0);
    if (heapArray[heap_size - 1].getName() == creature.getName())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MinArrayHeap::insert(Creature *c)
{
    if (capacity == heap_size)
    {
        resizeArray();
    }
    heapArray[heap_size] = *c;
    heap_size++;
    int i = heap_size - 1;
    while (i != 0 && heapArray[parent(i)].getName() > (heapArray + i)->getName())
    {
        swap(&heapArray[i], &heapArray[parent(i)]);
        i = parent(i);
    }
}

void MinArrayHeap::resizeArray()
{
    Creature *newHeapArray = new Creature[capacity * 2];

    for (int i = 0; i < capacity; i++)
    {
        newHeapArray[i] = heapArray[i];
    }

    delete[] heapArray;
    heapArray = newHeapArray;
    capacity *= 2;
}

void MinArrayHeap::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && heapArray[l].getName() < heapArray[i].getName())
    {
        smallest = l;
    }
    if (r < heap_size && heapArray[r].getName() < heapArray[smallest].getName())
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&heapArray[i], &heapArray[smallest]);
        minHeapify(smallest);
    }
}

void MinArrayHeap::display()
{
    if (IsEmpty())
    {
        cout << "There are no elements to display" << endl;
    }
    else
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << heapArray[i].getName() << endl;
        }
    }
}

void MinArrayHeap::saveToFile()
{
    for (int i = 0; i < heap_size; i++)
    {
        (heapArray + i)->printCreatureToFile("savedCreatures.txt");
    }
}

int MinArrayHeap::getNumberOfNodes() { return heap_size; }

int MinArrayHeap::getHeight() { return ceil(log2(heap_size + 1)); }

bool MinArrayHeap::IsEmpty() { return (heap_size == 0) ? true : false; }

#endif