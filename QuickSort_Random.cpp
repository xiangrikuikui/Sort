#include<iostream>  
#include<cstdlib>
#include<ctime>
using namespace std;
void quicksort_random(int a[], int p, int r);
int partition(int a[], int p, int r);
int partition_random(int a[], int p, int r);
int main()
{
	//int array[] = { 2,8,7,1,3,5,6,4 };
	int array[] = { 1,45,34,65,12,43,67,5,78,10,3,70,40 };
	int k;
	int len = sizeof(array) / sizeof(int);
	cout << "len: " << len << endl;
	cout << "The orginal arrayare:" << endl;
	for (k = 0; k < len; k++)
		cout << array[k] << ",";
	cout << endl;
	quicksort_random(array, 0, len);
	cout << "The sorted arrayare:" << endl;
	for (k = 0; k < len; k++)
		cout << array[k] << ",";
	cout << endl;
	system("pause");
	return 0;
}
int partition(int a[], int p, int r) //r表示数组长度
{
	int x = a[r - 1]; //以最后一个数为基准
	int i = p - 1;
	//cout << endl << "x: " << x << endl;
	for (int j = p; j < r - 1; j++)
	{
		if (a[j] <= x)
		{
			i++;
			if (i == j)
				continue;
			//cout << "j: " << j << ", i: " << i << endl;
			//cout << "a[i]: " << a[i] << ", a[j]: " << a[j] << endl;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i + 1];
	a[i + 1] = a[r - 1];
	a[r - 1] = temp;
	//for (int k = 0; k < r; k++)
	//cout << a[k] << ",";
	//cout << endl << "i + 1: " << i + 1 << endl;
	return i + 1;
}
int partition_random(int a[], int p, int r)
{
	int i = rand() % (r - p) + p;
	//cout << endl << "i: " << i;
	int temp = a[i];
	a[i] = a[r - 1];
	a[r - 1] = temp;
	//cout << endl;
	//for (int k = 0; k < r; k++)
		//cout << a[k] << ",";
	return partition(a, p, r);
}
void quicksort_random(int a[], int p, int r)
{
	if (p < r-1)
	{
		int q = partition_random(a, p, r);
		quicksort_random(a, p, q);
		quicksort_random(a, q + 1, r);
	}
}