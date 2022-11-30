#ifndef __MMS_H__
#define __MMS_H__

// number of elements in array
#define MAX 10

// number of threads
#define THREAD_MAX 4

using namespace std;

bool selectionUsed;// =false;

// array of size MAX
int a[MAX];
int part;// = 0;

// merge function for merging two parts
void merge(int low, int mid, int high);
// merge sort function
void merge_sort(int low, int high);
// thread function for multi-threading
void* merge_sort(void* arg);
// selection sort function
void selectionSort(int arr[], int n);
//swap function
void swap(int *xp, int *yp);

#endif