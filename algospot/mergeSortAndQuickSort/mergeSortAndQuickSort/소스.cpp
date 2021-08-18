#include <iostream>

const int MAX = 10;
int n;
using namespace std;

int sorted[MAX];

void merge(int* arr, int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (arr[i] < arr[j])
		{
			sorted[k] = arr[i];
			i++;
			k++;
		}
		else
		{
			sorted[k] = arr[j];
			j++;
			k++;
		}
	}

	while (i <= mid)
	{
		sorted[k++] = arr[i++];
	}

	while (j <= right)
	{
		sorted[k++] = arr[j++];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = sorted[i];
	}
}
void mergeSort(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

void quicksort(int* arr, int left, int right)
{
	
	if (left >= right) // recursive function은 모든 경우의 base case를 고려하지 않으면 infinity recursive에 빠져 stack overflow를 일으킨다
		return;

	int pivot = arr[left];
	int k = left;
	for (int i = left + 1; i <= right; i++)
	{
		if (arr[i] < pivot)
			sorted[k++] = arr[i];
	}
	int iPivot = k;
	sorted[k++] = pivot;
	for (int i = left + 1; i <= right; i++)
	{
		if (arr[i] >= pivot)
			sorted[k++] = arr[i];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = sorted[i];
	}
	quicksort(arr, left, iPivot - 1);
	quicksort(arr, iPivot+1, right);
}

void printArr(int* arr)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	return;
}

int main()
{
	cin >> n;

	int arr[MAX];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//mergeSort(arr, 0, n - 1);
	//quicksort(arr, 0, n - 1);

	printArr(sorted);

}