#include<iostream>
using namespace std;
void mergearray(int a[], int first, int mid, int last, int temp[])
{
	int i = first, j = mid + 1;
	int m = mid,   n = last;
	int k = 0;
	
	while (i <= m && j <= n)
  {
		if (a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	
	while (i <= m)
		temp[k++] = a[i++];
	
	while (j <= n)
		temp[k++] = a[j++];
	
	for (i = 0; i < k; i++)
		a[first + i] = temp[i];
}
void mergesort(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		mergesort(a, first, mid, temp);    //左边有序
  	mergesort(a, mid + 1, last, temp); //右边有序
		mergearray(a, first, mid, last, temp); //再将二个有序数列合并
	}
}
 
bool MergeSort(int a[], int n)
{
	int *p = new int[n];
	if (p == NULL)
		return false;
	mergesort(a, 0, n - 1, p);
	delete[] p;
	return true;
}

int main()
{
	int t,n,*seq;
	cin>>t;
  for(int i=0;i<t;i++)
	{
		cin>>n;
		seq=new int[n];
		int *temp=new int[n];
		for(int j=0;j<n;j++)
			cin>>seq[j];
		mergesort(seq,0,n-1,temp);
		for(int j=0;j<n;j++)
			cout<<seq[j]<<" ";
		cout<<endl;
  	delete [] seq;
	}
}