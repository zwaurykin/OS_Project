#ifndef __MQS_H__
#define __MQS_H__

#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX 900000

void *run(void *p); /* threads call this function */
int array_master[MAX];
void merge(int arr[], int left, int middle, int right);
// function to swap two elements in the array
void swap(int *a, int *b);
// function to partition in the array
int partition(int arr[], int low, int high);
/* The main function that implements QuickSort */
void quickSort(int arr[], int low, int high);




#endif