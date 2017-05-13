#include<iostream>
#include<math.h>
using namespace std;

void Merge(int m[], int first,int mid,int last,int temp[])
{
	int i = first, j = mid+1,k=0;
	while (i <= mid && j <= last)
	{
		if (m[i] < m[j])temp[k++] = m[i++];
		else temp[k++] = m[j++];
	}
	while (i <= mid)temp[k++]=m[i++];

	while (j <= last)temp[k++] = m[j++];

	for (int i = 0; i < k; i++)	m[first + i] = temp[i];

}
void Mergesort(int m[], int first, int last,int temp[])
{
	int mid;
	if (first < last)
	{
		mid = (first + last) / 2;
		Mergesort(m, first, mid,temp);
		Mergesort(m, mid + 1, last,temp);
		Merge(m, first, mid, last,temp);
	}
}

int main()
{
	int m[1000]; int temp[1000];
	for (int i = 0; i < 1000; i++)m[i] = rand()/20;
	Mergesort(m, 0, 999,temp);
	for (int i = 0; i < 1000; i++)cout << m[i] << " ";
	system("pause");
	return 0;
}