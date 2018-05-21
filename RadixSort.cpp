#include<iostream>
#include<vector>
using namespace std;
//��������int num[]��C++��vector���ݵ�ַʱ,vector��Ҫ������,����,û���õ���ȷ��ַ,
//��Ϊvector��������һ�������,��˴�ֵ��ò�����ȷ���,��������˻�Ϊָ��,��˿���ֱ�Ӵ�ֵ.
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

//��������
void RadixSort(vector<int> &data, int n)
{
	int maxBit = MaxBit(data, n);
	int* tmpData = new int[n];
	int* cnt = new int[10]; //Ͱ�����ݸ���
	int  radix = 1;
	int  i, j, binNum;

	for (i = 1; i <= maxBit; i++)
	{
		for (j = 0; j < 10; ++j)
			cnt[j] = 0;
		for (j = 0; j < n; j++)
		{
			binNum = (data[j] / radix) % 10;
			cnt[binNum]++; //ͳ�Ƹ���ͰҪװ������ݸ���
		}
		
		for (binNum = 1; binNum< 10; binNum++)
			cnt[binNum] = cnt[binNum - 1] + cnt[binNum];  //cnt[binNum]��ʾ����Ͱ���ұ߽�����
		
		for (j = n - 1; j >= 0; j--)  //����Ҫ��������ɨ�裬��֤�����ȶ���
		{
			binNum = (data[j] / radix) % 10;  //����ؼ���ĵ�kλ�����֣� ���磺576�ĵ�3λ��5
			tmpData[cnt[binNum] - 1] = data[j];  //�����Ӧ��Ͱ�У�count[binNum]-1�ǵ�binNum��Ͱ���ұ߽�����
			cnt[binNum]--;  //��ӦͰ��װ����������-1
		}
		
		for (j = 0; j < n; j++)
			data[j] = tmpData[j];  //���ѷ���õ�Ͱ�������ٵ���������ʱ���Ƕ�Ӧ��ǰλ������ı�
		
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
	cout << "before sort��";
	for (int i = 0; i < len; i++)
		cout << data[i] << " ";
	cout << endl;
	RadixSort(data, len);
	cout << "after sort��";
	for (int i = 0; i < len; i++)
		cout << data[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}