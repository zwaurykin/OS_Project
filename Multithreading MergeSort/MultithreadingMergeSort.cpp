#include <iostream>
#include "MultithreadingMergeSort.h"
#include <pthread.h>
#include <time.h>

#define TEST

//selectionSort()
void test1(void)
{
    int test_arr[10] = {0, 98, 45, 77, 26, 14, 33, 69, 420, 422};
    selectionSort(test_arr, 10);
    for (int i = 0; i < MAX; i++)
        cout << test_arr[i] << " ";
    cout << endl;
}
//merge()
void test2(void)
{
	for (int i = 0; i < MAX; i++)
	{
		a[i] = rand() % 10;
	}
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";
	cout << endl;
	merge(0, 5, 10);
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";
	cout << endl;
}

//merge_sort()
void test3(void)
{
	for (int i = 0; i < MAX; i++)
	{
		a[i] = rand() % 10;
	}
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";
	cout << endl;
	merge_sort(0, 10);
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";
	cout << endl;
}

void merge(int low, int mid, int high)
{
	int *left = new int[mid - low + 1];
	int *right = new int[high - mid];

	// n1 is size of left part and n2 is size
	// of right part
	int n1 = mid - low + 1, n2 = high - mid, i, j;

	// storing values in left part
	// cout <<"LEFT ";

	for (i = 0; i < n1; i++)
	{
		left[i] = a[i + low];
		// cout << a[i] << " ";
	}
	// storing values in right part
	// cout <<"RIGHT ";

	for (i = 0; i < n2; i++)
	{
		right[i] = a[i + mid + 1];
		// cout << a[i] << " ";
	}
	// cout << a[i] << " ";

	int k = low;
	i = j = 0;

	// merge left and right in ascending order
	while (i < n1 && j < n2)
	{
		if (left[i] <= right[j])
			a[k++] = left[i++];
		else
			a[k++] = right[j++];
	}

	// insert remaining values from left
	while (i < n1)
	{
		a[k++] = left[i++];
	}

	// insert remaining values from right
	while (j < n2)
	{
		a[k++] = right[j++];
	}
}

// merge sort function
void merge_sort(int low, int high)
{
	// calculating mid point of array
	int mid = low + (high - low) / 2;
	if (low < high)
	{

		// calling first half
		merge_sort(low, mid);

		// calling second half
		merge_sort(mid + 1, high);

		// merging the two halves
		merge(low, mid, high);
	}
}

// thread function for multi-threading
void *merge_sort(void *arg)
{
	// which part out of 4 parts
	int thread_part = part++;

	// calculating low and high
	int low = thread_part * (MAX / 4);
	int high = (thread_part + 1) * (MAX / 4) - 1;

	// evaluating mid point
	int mid = low + (high - low) / 2;
	if (low < high)
	{
		merge_sort(low, mid);
		merge_sort(mid + 1, high);
		merge(low, mid, high);
	}

	pthread_exit(0);
}

// Swap function
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of
	// unsorted subarray
	for (i = 0; i < n - 1; i++)
	{

		// Find the minimum element in
		// unsorted array
		min_idx = i;
		for (j = i + 1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element
		// with the first element
		if (min_idx != i)
			swap(&arr[min_idx], &arr[i]);
	}
}

void runTestCases(void)
{
	test1();
	test2();
	test3();
}

// Driver Code
int main()
{

#ifdef TEST
	runTestCases();
#else
	srand(time(NULL));
	// generating random values in array
	for (int i = 0; i < MAX; i++)
	{
		a[i] = rand() % 1000;
	}
	cout << "Given array is";
	cout << endl;
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";
	cout << endl;
	cout << endl;
	// t1 and t2 for calculating time for
	// merge sort
	clock_t t1, t2;

	t1 = clock();
	if (MAX < 100)
	{
		selectionSort(a, MAX);
		selectionUsed = true;
	}
	else
	{

		pthread_t threads[THREAD_MAX];

		// creating 4 threads
		for (int i = 0; i < THREAD_MAX; i++)
		{
			pthread_create(&threads[i], NULL, merge_sort,
						   (void *)NULL);
		}

		// joining all 4 threads
		for (int i = 0; i < 4; i++)
		{
			pthread_join(threads[i], NULL);
		}

		// merging the final 4 parts
		merge(0, (MAX / 2 - 1) / 2, MAX / 2 - 1);
		merge(MAX / 2, MAX / 2 + (MAX - 1 - MAX / 2) / 2, MAX - 1);
		merge(0, (MAX - 1) / 2, MAX - 1);
	}
	t2 = clock();
	cout << endl;
	// displaying sorted array
	cout << "Sorted array via ";

	selectionUsed ? cout << "Selection " : cout << "Merge ";
	cout << "sort is:";
	cout << endl;
	for (int i = 0; i < MAX; i++)
		cout << a[i] << " ";
	cout << endl;
	// time taken by merge sort in seconds
	cout << endl;
	cout << "Time taken: " << (t2 - t1) / (double)CLOCKS_PER_SEC << endl;
#endif
	return 0;
}
