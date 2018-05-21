#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//在用数组int num[]和C++的vector传递地址时,vector需要传引用,否则,没法得到正确地址,
//因为vector本质上是一个类对象,因此传值会得不到正确结果,而数组会退化为指针,因此可以直接传值.
void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxIdx = index;
	if (left<len && arr[left] > arr[maxIdx]) maxIdx = left;
	if (right<len && arr[right] > arr[maxIdx]) maxIdx = right;  // maxIdx是3个数中最大数的下标
	if (maxIdx != index)                 // 如果maxIdx的值有更新
	{
		swap(arr[maxIdx], arr[index]);
		adjust(arr, len, maxIdx);       // 递归调整其他不满足堆性质的部分
	}

}
void heapSort(vector<int> &arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)  // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
	{
		adjust(arr, size, i);
	}
	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
		for (int j = 0; j < 5; j++)
			cout << arr[j] << " ";
		cout << endl;
		adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
	}
}

int main()
{
	//int array[] = { 1,5,7,2,6 };
	//vector<int>array = { 14,71,18,151,138,160,3,63,85,174,169,79,78 };
	//int len = sizeof(array) / sizeof(array[0]);
	vector<int>array = { 1,5,7,2,6 };
	int len = array.size();
	heapSort(array, len);
	for (auto it : array)
	{
		cout << it << " ";
	}
	system("pause");
	return 0;
}