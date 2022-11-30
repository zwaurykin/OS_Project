#ifndef __SQS_H__
#define __SQS_H__

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX 101
int arr[MAX];
bool selectionUsed = false;

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
//function that implements QuickSort
void quickSort(int arr[], int low, int high);
/* function to print an array */
void printArray(int A[], int size);
void merge(int arr[], int left, int middle, int right);


#endif //__SQS_H__