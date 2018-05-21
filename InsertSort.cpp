#include<iostream>
int main()
{
	using namespace std;
	int a[] = { 21, 13, 46, 15, 48, 6, 19, 37, 22 };
	int n;
	n = sizeof(a) / sizeof(a[0]); //数组长度
	//cout << l << endl;
	for (int j = 1; j < n; j++)
	{
		int key = a[j];
		//cout << endl << "key:" << key << endl;
		int i = j - 1;
		while (i >= 0 && a[i] > key)
			{
				a[i + 1] = a[i];
				//cout << j << "," << i << ":" << a[i + 1] << ";  ";
				//for (int i = 0; i < l; i++)
					//cout << a[i] << '\t';
				i = i - 1;
			}
			//cout << endl;
		a[i + 1] = key;
		//for (int i = 0; i < l; i++)
			//cout << i <<":"<<a[i] << '\t';
		//cout << endl;
	}
	for (int i = 0; i < n; i++)
		cout << a[i]<<'\t';
	system("pause");
}
