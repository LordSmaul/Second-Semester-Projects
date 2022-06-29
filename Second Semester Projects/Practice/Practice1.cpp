#include <bits/stdc++.h>
using namespace std;

// Selection Sort Function
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int smallestIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[smallestIndex])
            {
                smallestIndex = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
    }
}

// Insertion Sort function
void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;

        while (j > 0 && arr[j] < arr[j - 1])
        {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
            j--;
        }
    }
}

int main()
{

    int selectArray[8] = {100, 87, 76, 56, 34, 12, 2, 1};
    int insertArray[10] = {89, 76, 32, 17, 12, 10, 4, 2, 3, 1};
    int selectSize = 8;
    int insertSize = 10;

    cout << "Unsorted Array 1:" << endl;

    for (int i = 0; i < selectSize; i++)
    {
        cout << selectArray[i] << " ";
    }

    selectionSort(selectArray, selectSize);

    cout << "\nSorted Array 1:" << endl;

    for (int i = 0; i < selectSize; i++)
    {
        cout << selectArray[i] << " ";
    }


    cout << "\nUnsorted Array 2:" << endl;

    for (int i = 0; i < insertSize; i++)
    {
        cout << insertArray[i] << " ";
    }

    insertionSort(insertArray, insertSize);

    cout << "\nSorted Array 2:" << endl;

    for (int i = 0; i < insertSize; i++)
    {
        cout << insertArray[i] << " ";
    }

    return 0;
}