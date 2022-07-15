/*
 * Title: hw11_1.cpp
 * Abstract: This program displays the performance of three different sorting algorithms.
 * Author: Jasdeep Singh Dhillon
 * ID: 2867
 * Date: 12/5/2020

	Heap Sort: geeksforgeeks.org
	// https://www.geeksforgeeks.org/cpp-program-for-heap-sort/
	Merge Sort: geeksforgeeks.org
	// https://www.geeksforgeeks.org/merge-sort/
	Quick Sort: geeksforgeeks.org
	// https://www.geeksforgeeks.org/quick-sort/

*/

#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<chrono>
using namespace std;
using namespace std::chrono;

void insertionSort(int arr[], int n);
void mergeSort(int arr[],int l,int r);
void merge(int arr[], int l, int m, int r);
void swap(int* a, int* b);
int partition (int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main()
{
	int size;
	cout << "Enter input size: ";
	cin >> size;

    cout << "";

    int option;
    cout << "Choose Option: ";
    cin >> option;
    for(int i=0; i<3; i++) {
        int *insert = new int[size];
        int *merge = new int[size];
        int *quick = new int[size];
        srand(time(NULL));
        if(option == 1) {
            int r = rand();
            for(int i=0; i<size; i++)
            {
                insert[i] = r + i;
            }
            for(int i=0; i<size; i++)
            {
                merge[i] = insert[i];
            }
            for(int i=0; i<size; i++)
            {
                quick[i] = merge[i];
            }
        } else if(option == 2) {
            for(int i=0; i<size; i++)
            {
                insert[i] =  size - 1 - i;
            }
            for(int i=0; i<size; i++)
            {
                merge[i] = insert[i];
            }
            for(int i=0; i<size; i++)
            {
                quick[i] = merge[i];
            }

        } else if (option == 3) {
            for(int i=0; i<size; i++)
            {
                insert[i]=rand();
            }
            for(int i=0; i<size; i++)
            {
                merge[i] = insert[i];
            }
            for(int i=0; i<size; i++)
            {
                quick[i] = merge[i];
            }
            cout << "===================== Execution Time ====================\n";
            auto start = high_resolution_clock::now(); 
            insertionSort(insert, size);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start); 
            cout << "Insertion sort:    " << (float)duration.count()/1000;
            cout << " milliseconds" << endl;
            delete [] insert;

            start = high_resolution_clock::now();
            mergeSort(merge, 0, size-1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Merge sort:   " << (float)duration.count()/1000;
            cout << " milliseconds" << endl;
            delete [] merge;

            start = high_resolution_clock::now();
            quickSort(quick, 0, size-1);
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "Quick sort:   " << (float)duration.count()/1000;
            cout << " milliseconds" << endl;
            delete [] quick;
            cout << "=========================================================\n";
        }
        
    }
	
}


/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Heap Sort taken from geeksforgeeks.org
// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2 * i + 1; // left = 2*i + 1 
    int r = 2 * i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i = n - 1; i >= 0; i--) { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
} 

// Merge sort taken from geeksforgeeks.org
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    int L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

// Quick sort taken from geeksforgeeks.org
// A utility function to swap two elements  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; // pivot  
    int i = (low - 1); // Index of smaller element  
  
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
/* The main function that implements QuickSort  
arr[] --> Array to be sorted,  
low --> Starting index,  
high --> Ending index */
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partition(arr, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  
