#include <bits/stdc++.h>
using namespace std;

// function to print array
void printArray(int *A, int n)
{

    if (n == 0)
    {
        cout << "Empty Array" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

// Bubble Sort function
void bubbleSort(int *A, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

// Insertion Sort function
void insertionSort(int *A, int n)
{
    int key, j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

// Selection Sort function
void selectionSort(int *A, int n)
{
    int indexOfMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
        }
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
    }
}

// function to divide array in two sub-arrays such that
// all smaller elements wrt pivot are on left and greater on right
int partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

// Quick Sort function
void quickSort(int *A, int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high);
        quickSort(A, low, partitionIndex - 1);  // quicksort on left sub-array
        quickSort(A, partitionIndex + 1, high); // quicksort on right sub-array
    }
}

// Merging two Sorted sub-array
void merge(int *A, int mid, int low, int high)
{
    int i, j, k;
    int *B = new int[high + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    delete (B);
}

// Merge Sort function
void mergeSort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{
    int *arr = new int[10];

    arr[0] = {3};
    arr[1] = {9};
    arr[2] = {4};
    arr[3] = {2};
    arr[4] = {6};
    arr[5] = {1};
    arr[6] = {8};
    arr[7] = {0};
    arr[8] = {7};
    arr[9] = {5};

    printArray(arr, 10);

    mergeSort(arr, 0, 9); // Time complexity:  O(n*log(n)) , Space complexity:  O(n)
    printArray(arr, 10);

    bubbleSort(arr, 10); // Time complexity:  O(n^2) , Space complexity:  O(1)
    printArray(arr, 10);

    insertionSort(arr, 10); // Time complexity:  O(n^2) , Space complexity:  O(1)
    printArray(arr, 10);

    selectionSort(arr, 10); // Time complexity:  O(n^2) , Space complexity:  O(1)
    printArray(arr, 10);

    quickSort(arr, 0, 9); // Time complexity:  O(n^2) , Space complexity:  O(1) , Average/best case Time complexity:  O(n*log(n))
    printArray(arr, 10);

    delete (arr);
    return 0;
}