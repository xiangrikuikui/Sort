#include<iostream>  
using namespace std;

int partition(int a[], int p, int r) //r表示数组的长度
{
	int x = a[r - 1]; //以最后一个数为基准
	int i = p - 1;
	//cout << "x: " << x << endl;
	for (int j = p; j < r - 1; j++)
	{
		if (a[j] <= x)
		{
			i++;
			if (i == j)
				continue;
			//cout << "exchange" << endl;
			//cout << "j: " << j << ", i: " << i << endl;
			//cout << "a[i]: " << a[i] << ", a[j]: " << a[j] << endl;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	int temp = a[i + 1];  //当j遍历完p到r-2时，交换a[r]与a[i+1]
	a[i + 1] = a[r-1];
	a[r-1] = temp;
	//for (int k = 0; k < r; k++)
		//cout << a[k] << ",";
	//cout << endl << "i + 1: " << i + 1 << endl;
	return i + 1;
	//return i;
}
void quicksort(int a[], int p, int r)
{
	if (p < r - 1)
	{
		int q = partition(a, p, r);
		quicksort(a, p, q);
		quicksort(a, q + 1, r);
	}
}
int main()
{
	//int array[] = { 5,8,10,7,6,9 };
	int array[] = { 24,34,45,65,12,45,67,35,5,78,10,3,70,35 };
	int k;
	int len = sizeof(array) / sizeof(int);
	cout << "len: " << len << endl;
	cout << "The orginal array are:" << endl;
	for (k = 0; k < len; k++)
		cout << array[k] << " ";
	cout << endl;
	quicksort(array, 0, len);
	cout << "The sorted array are:" << endl;
	for (k = 0; k < len; k++)
		cout << array[k] << " ";
	cout << endl;
	system("pause");
	return 0;
}
/*
int partition(int a[], int p, int r) //r表示数组的长度
{
	int x = a[r - 1]; //以最后一个数为基准
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (a[j] <= x)
		{
			i++;
			if (i == j)
				continue;
			int temp = a[i]; a[i] = a[j]; a[j] = temp;
		}
	}
	return i;
}
void quicksort(int a[], int p, int r)
{
	if (p < r - 1)
	{
		int q = partition(a, p, r);
		quicksort(a, p, q);
		quicksort(a, q + 1, r);
	}
}
*/