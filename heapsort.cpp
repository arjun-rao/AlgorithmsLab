#include <iostream>

using namespace std;

void heapify(int arr[],int n,int root)
{

	int left,right,largest;
	largest = root;
	left = 2*root+1;
	right= 2*root+2;

	if(left <n && arr[left] > arr[largest])
		largest = left;

	if(right <n && arr[right] >arr[largest])
		largest= right;

	if(largest!=root)
	{
		swap(arr[root],arr[largest]);

		heapify(arr,n,largest);

	}


}


void heapsort(int arr[],int n)
{
	for(int i=n/2-1;i>=0;i--)
		heapify(arr,n,i);

	for(int i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);

		heapify(arr,i,0);
	}

}



int main()
{
	int *a,n;
	cin>>n;
	a = new int[n];
	for(int i=0;i<n;i++)cin>>a[i];
	heapsort(a,n);
	cout<<"Sorted:\n";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
	cout<<endl;

}
