#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//��������int num[]��C++��vector���ݵ�ַʱ,vector��Ҫ������,����,û���õ���ȷ��ַ,
//��Ϊvector��������һ�������,��˴�ֵ��ò�����ȷ���,��������˻�Ϊָ��,��˿���ֱ�Ӵ�ֵ.
void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int maxIdx = index;
	if (left<len && arr[left] > arr[maxIdx]) maxIdx = left;
	if (right<len && arr[right] > arr[maxIdx]) maxIdx = right;  // maxIdx��3��������������±�
	if (maxIdx != index)                 // ���maxIdx��ֵ�и���
	{
		swap(arr[maxIdx], arr[index]);
		adjust(arr, len, maxIdx);       // �ݹ������������������ʵĲ���
	}

}
void heapSort(vector<int> &arr, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)  // ��ÿһ����Ҷ�����жѵ���(�����һ����Ҷ��㿪ʼ)
	{
		adjust(arr, size, i);
	}
	for (int i = size - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
		for (int j = 0; j < 5; j++)
			cout << arr[j] << " ";
		cout << endl;
		adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
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