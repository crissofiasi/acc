#include "stdafx.h"
#include "SortAlgs.h"
#include <iostream>
void SortAlgs::swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// A function to implement bubble sort 
void SortAlgs::bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		// IF no two elements were swapped by inner loop, then break 
		if (swapped == false)
			break;
	}

}

void SortAlgs::rankingSort(int arr[], int n) {
	int* rank = new int[n];
	int* sortedArr = new int[n];
	int i, j;
	for (i = 0; i < n; i++)
		rank[i] = sortedArr[i] = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < i; j++)
			if (arr[i] >= arr[j])
				rank[i]++;
			else
				rank[j]++;
	for (i = 0; i < n; i++)
		sortedArr[rank[i]] = arr[i];
	for (i = 0; i < n; i++)
		arr[i] = sortedArr[i];
	delete[] rank;
	delete[] sortedArr;
}


void SortAlgs::merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int *L = new int[n1], *R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

	delete[] L;
	delete[] R;
}

void SortAlgs::mergeSort_(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort_(arr, l, m);
		mergeSort_(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

void SortAlgs::mergeSort(int arr[], int n) {
	mergeSort_(arr, 0, n - 1);
}




/*The parameter dir indicates the sorting direction, ASCENDING
or DESCENDING; if (a[i] > a[j]) agrees with the direction,
then a[i] and a[j] are interchanged.*/
void SortAlgs::compAndSwap(int a[], int i, int j, int dir)
{
	if (dir == (a[i] > a[j]))
		swap(&a[i], &a[j]);
}

/*It recursively sorts a bitonic sequence in ascending order,
if dir = 1, and in descending order otherwise (means dir=0).
The sequence to be sorted starts at index position low,
the parameter cnt is the number of elements to be sorted.*/
void SortAlgs::bitonicMerge(int a[], int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;
		for (int i = low; i < low + k; i++)
			compAndSwap(a, i, i + k, dir);
		bitonicMerge(a, low, k, dir);
		bitonicMerge(a, low + k, k, dir);
	}
}

/* This function first produces a bitonic sequence by recursively
sorting its two halves in opposite sorting orders, and then
calls bitonicMerge to make them in the same order */
void SortAlgs::bitonicSort_(int a[], int low, int cnt, int dir)
{
	if (cnt > 1)
	{
		int k = cnt / 2;

		// sort in ascending order since dir here is 1 
		bitonicSort_(a, low, k, 1);

		// sort in descending order since dir here is 0 
		bitonicSort_(a, low + k, k, 0);

		// Will merge wole sequence in ascending order 
		// since dir=1. 
		bitonicMerge(a, low, cnt, dir);
	}
}

/* Caller of bitonicSort for sorting the entire array of
length N in ASCENDING order */
void SortAlgs::bitonicSort(int arr[], int N)
{
	bitonicSort_(arr, 0, N, 1);
}

void SortAlgs::linearSort(int arr[], int n) {
	int max, min, i,n2;
	max = min = arr[0];
	for (i = 1; i < n; i++)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}
	n2 = max - min+1;
	int *c = new int[n2];

	for (i = 0; i < n2+1; i++)
		c[i] = 0;

	for (i = 0; i < n; i++)
		c[arr[i] - min]++;
	for (i = 1; i < n2+1; i++)
		c[i] = c[i] + c[i - 1];

	int *b = new int[n];
	for (i = n - 1; i >= 0; i--)
	{
		int x = arr[i]-min;
		b[c[x]-1] = arr[i];
		c[x]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = b[i];
	

//	delete[] b;
	//delete[] c;
}








