#include<iostream>
using namespace std;
void shellsort(int a[], int n)
{
	int gap;
	for (gap = 3; gap > 0; gap--)
	{
		for (int i = 0; i < gap; i++)
		{
			for (int j = i; j < n; j = j + gap)
			{
				cout << "a[" << j << "]:" << a[j] << " ";
				int key = a[j];
				int k = j - gap;
				while (k >= 0 && a[k] > key)
				{
					a[k + gap] = a[k];
					k = k - gap;
				}
				a[k + gap] = key;
			}
			cout << endl;
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
}
int main()
{
	int a[] = { 70,30,40,10,80,20,90,100,75,60,45 };
	int n = sizeof(a) / sizeof(a[0]);
	shellsort(a, n);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	system("pause");
}
