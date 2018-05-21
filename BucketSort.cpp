#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int val;
	Node *next;
};
//void printnode(Node *p)
//{
//	Node *h = p;
//	cout << "print val: ";
//	while (h)
//	{
//		cout << h->val << " ";
//		h = h->next;
//	}
//	cout << endl;
//}
void BucketSort(vector<int>a, int bucket_size)
{
	Node **bucket_table = (Node **)malloc(bucket_size * sizeof(Node *));
	for (int i = 0; i < bucket_size; i++)
	{
		bucket_table[i] = (Node *)malloc(sizeof(Node));
		bucket_table[i]->val = 0; //��¼��ǰͰ�е�������
		bucket_table[i]->next = NULL;
	}
	for (int i = 0; i < a.size(); i++)
	{
		Node *pnode = (Node *)malloc(sizeof(Node));
		pnode->val = a[i];
		pnode->next = NULL;

		int index = a[i] / 10; //ӳ�亯������Ͱ��
		Node *p = bucket_table[index]; //ÿ��ѭ��p��ָ��Ͱ�����������ͷָ�룬��ʼbucket_table[i]->val=0��p->val=0

		if (p->val == 0)
		{
			bucket_table[index]->next = pnode;
			(bucket_table[index]->val)++;  //Ͱ�е�������+1
			//printnode(p);
		}
		else
		{
			while (p->next != NULL && p->next->val <= pnode->val)
				p = p->next;
			//printnode(p);
			pnode->next = p->next;
			p->next = pnode;
			(bucket_table[index]->val)++;
		}
	}
	for (int i = 0; i < bucket_size; i++)
	{
		cout << "bucket " << i << ": ";
		for (Node *k = bucket_table[i]->next; k != NULL; k = k->next)
			cout << k->val << " ";
		cout << endl;
	}
	cout << endl;
	cout << "after sort: ";
	for (int i = 0; i < bucket_size; i++)
	{
		for (Node *k = bucket_table[i]->next; k != NULL; k = k->next)
			cout << k->val << " ";
	}
	cout << endl;
}
int main()
{
	vector<int>a = { 49,38,65,97,76,13,47,46,27,34,43 };
	cout << "befor sort: ";
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	cout << endl << endl;
	BucketSort(a, 10);
	system("pause");
}