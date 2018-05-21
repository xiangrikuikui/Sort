#include<iostream>
#include<climits>
using namespace std;
void merge(int A[], int p, int q, int r);
void mergeSort(int A[], int p, int r);
int main()
{
	int A[] = { 49,38,65,24,55,18,64,97,6,76,13,27 };
	int n = sizeof(A) / sizeof(A[0]);
	mergeSort(A, 0, n - 1);
	for (int i = 0; i < n; i++)
		cout << A[i] << "  ";
	system("pause");
}
void merge(int A[], int p, int q, int r)
{
	int i, j, k;
	int n1 = q - p + 1;
	int n2 = r - q;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	for (i = 0; i < n1; i++)
		L[i] = A[i + p];
	for (j = 0; j < n2; j++)
		R[j] = A[j + q + 1];
	L[n1] = INT_MAX;
	R[n2] = INT_MAX; //若没有L[n1],L[n2],会有内存中的数据出现在排序中
	i = 0; j = 0;
	for (k = p; k <= r; k++)
	{
		if (L[i] <= R[j])
			A[k] = L[i++];
		else
			A[k] = R[j++];
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


