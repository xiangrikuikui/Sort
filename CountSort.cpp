#include<iostream>
void CountingSort(int a[], int n, int k);
int main()
{
	int a[] = { 1,45,34,65,12,43,10,67,5,78,10,3,70,40 };
	//int a[] = { 2,5,3,0,2,3,0,3 };
	int len = sizeof(a) / sizeof(a[0]);
	int max = a[0];
	for (int i = 1; i < len; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	//std::cout << len << ", " << max << std::endl;
	CountingSort(a, len, max);
	system("pause");
}
void CountingSort(int a[], int n, int k)  //n个输入元素，每个都是0-k区间的一个整数
{
	int *c = new int[k + 1];
	int *b = new int[n];
	for (int i = 0; i < k + 1; i++)
		c[i] = 0;
	for (int j = 0; j < n; j++)
		c[a[j]] = c[a[j]] + 1; //共有c[a[j]]个数与a[j]相同
	for (int i = 1; i < k + 1; i++)
		c[i] = c[i] + c[i - 1];  //小于等于a[j]的数共有c[i]个
	for (int j = 0; j < n; j++)
	{
		b[c[a[j]] - 1] = a[j];
		c[a[j]] = c[a[j]] - 1;
	}
	for (int i = 0; i < n; i++)
		std::cout << b[i] << " ";
	delete []c;
	delete []b;
}
