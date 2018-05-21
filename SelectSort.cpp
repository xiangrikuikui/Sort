#include<iostream>
int main()
{
	using namespace std;
	int a[] = { 21, 13, 46, 15, 48, 6, 19, 37, 22 };
	int n = sizeof(a) / sizeof(a[0]); //数组长度
	for (int i = 0; i < n - 1; i++)
	{
		cout << endl;
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		cout << "min:" << a[min] << ", a[i]:" << a[i] << endl;
		if (min != i)
		{
			int temp = a[i];
			a[i] = a[min];
			a[min] = temp;
		}
		cout << "min:" << a[min] << ", a[i]:" << a[i] << endl;
		for (int i = 0; i < n; i++)
			cout << a[i] << '\t';
	}
	system("pause");
}
