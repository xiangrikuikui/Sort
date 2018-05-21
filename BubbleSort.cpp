#include <iostream>
void bubble(int a[], int n);
int main()
{
	int a[] = { 93,13,21,46,15,48,3,19,37,22 };
	int n = sizeof(a) / sizeof(a[0]);
	bubble(a, n);
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	system("pause");
}
void bubble(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}














