#include<iostream>
using namespace std;
void merge(int A[], int p, int q, int r);
void mergeSort(int A[], int p, int r);
int main()
{
	int A[] = { 49,38,65,24,55,18,64,97,6,76,13,27 };
	int n = sizeof(A) / sizeof(A[0]);
	mergeSort(A, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << A[i] << " ";
	system("pause");
}
void merge(int A[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1];
	int *R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = A[i + p];
	for (j = 0; j < n2; j++)
		R[j] = A[j + q + 1];
	i = 0; j = 0;
	for (k = p; k <= r; k++)
	{
		if (i < n1 && j < n2)
		{
			if (L[i] < R[j])
			{
				A[k] = L[i++];
				continue;
			}
			else
			{
				A[k] = R[j++];
				continue;
			}
		}
		if (i < n1 && j >= n2)
		{
			A[k] = L[i++];
			continue;
		}
		if (i >= n1 && j < n2)
		{
			A[k] = R[j++];
			continue;
		}
	}
	delete[] L;
	delete[] R;
}

void mergeSort(int A[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		//递归过程，二路归并排序递归过程
		mergeSort(A, p, q);
		mergeSort(A, q + 1, r);

		//归并
		merge(A, p, q, r);
	}
}