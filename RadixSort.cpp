#include<iostream>
#include<vector>
using namespace std;
//在用数组int num[]和C++的vector传递地址时,vector需要传引用,否则,没法得到正确地址,
//因为vector本质上是一个类对象,因此传值会得不到正确结果,而数组会退化为指针,因此可以直接传值.
int MaxBit(vector<int> &data, int n)
{
	int maxBit = 1;
	int temp = 10;
	for (int i = 0; i < n; ++i)
	{
		while (data[i] >= temp)
		{
			temp *= 10;
			++maxBit;
		}
	}
	return maxBit;
}

//基数排序
void RadixSort(vector<int> &data, int n)
{
	int maxBit = MaxBit(data, n);
	int* tmpData = new int[n];
	int* cnt = new int[10]; //桶中数据个数
	int  radix = 1;
	int  i, j, binNum;

	for (i = 1; i <= maxBit; i++)
	{
		for (j = 0; j < 10; ++j)
			cnt[j] = 0;
		for (j = 0; j < n; j++)
		{
			binNum = (data[j] / radix) % 10;
			cnt[binNum]++; //统计各个桶要装入的数据个数
		}
		
		for (binNum = 1; binNum< 10; binNum++)
			cnt[binNum] = cnt[binNum - 1] + cnt[binNum];  //cnt[binNum]表示各个桶的右边界索引
		
		for (j = n - 1; j >= 0; j--)  //这里要从右向左扫描，保证排序稳定性
		{
			binNum = (data[j] / radix) % 10;  //求出关键码的第k位的数字， 例如：576的第3位是5
			tmpData[cnt[binNum] - 1] = data[j];  //放入对应的桶中，count[binNum]-1是第binNum个桶的右边界索引
			cnt[binNum]--;  //对应桶的装入数据索引-1
		}
		
		for (j = 0; j < n; j++)
			data[j] = tmpData[j];  //将已分配好的桶中数据再倒出来，此时已是对应当前位数有序的表
		
		radix = radix * 10;
	}
	delete[] tmpData;
	delete[] cnt;
}

int main()
{
	vector<int> data = { 73, 22, 93, 43, 156, 356, 55, 14, 28, 65, 39, 81 };
	//vector<int> data = { 73, 2, 14, 32 };
	int len = data.size();
	cout << "Radix Sort" << endl;
	cout << "before sort：";
	for (int i = 0; i < len; i++)
		cout << data[i] << " ";
	cout << endl;
	RadixSort(data, len);
	cout << "after sort：";
	for (int i = 0; i < len; i++)
		cout << data[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}