#pragma once
class SortAlgs {
private:
	void mergeSort_(int arr[], int l, int r);
	void merge(int arr[], int l, int m, int r);
	void bitonicSort_(int a[], int low, int cnt, int dir);
	void bitonicMerge(int a[], int low, int cnt, int dir);
	void compAndSwap(int a[], int i, int j, int dir);
public:
	void swap(int *xp, int *yp);
	void bubbleSort(int arr[], int n);
	void rankingSort(int arr[], int n);
	void mergeSort(int arr[], int n);
	void bitonicSort(int arr[], int n);
	void linearSort(int arr[], int n);
};
