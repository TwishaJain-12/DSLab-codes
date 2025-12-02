#include<iostream>
using namespace std;
void maxheapify(int ar[],int d,int c)
{
	int left=2*d;
	int right=2*d+1;
	int largest=d;
	if(left<c&&ar[left]>ar[largest])
	{
		largest=left;
	}
	else
	largest=d;
	if(right<c&&ar[right]>ar[largest]&&ar[right]>ar[left])
	largest=right;
	if(largest!=d)
	{
		int temp=ar[d];
		ar[d]=ar[largest];
		ar[largest]=temp;
		maxheapify(ar,largest,c);
	}
}
void buildmaxheap(int arr[],int l)
{
	int s=l;
	for(int j=s/2;j>0;j--)
	maxheapify(arr,j,s);
}
void minheapify(int arr[],int d,int c)
{
	int left=2*d;
	int right=2*d+1;
	int smallest=d;
	if(left<c&&arr[left]<arr[smallest])
	smallest=left;
	else
	smallest=d;
	if(right<c&&arr[right]<arr[smallest]&&arr[right]<arr[left])
	smallest=right;
	if(smallest!=d)
	{
		int temp=arr[d];
		arr[d]=arr[smallest];
		arr[smallest]=temp;
		minheapify(arr,smallest,c);
	}
}
void buildminheap(int arr[],int l)
{
	int s=l;
	for(int j=s/2;j>0;j--)
	minheapify(arr,j,s);
}
void printheap(int arr[],int c)
{
	cout<<endl;
	for(int i=1;i<c;i++)
	cout<<endl<<arr[i];
}
void heapsortmax(int arr[],int c)
{
	if(c>1)
	{
		int temp=arr[c-1];
		arr[c-1]=arr[1];
		arr[1]=temp;
		c--;
		buildmaxheap(arr,c);
		heapsortmax(arr,c);
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements you want to enter in the array:";
	cin>>n;
	int a[n+1];
	a[0]=-1;
	cout<<"Enter the elements:\n";
	for(int i=1;i<n+1;i++)
	cin>>a[i];
	buildmaxheap(a,n+1);
	cout<<endl<<"Max heap:";
	printheap(a,n+1);
	heapsortmax(a,n+1);
	cout<<endl<<"Sorted array in increasing order:";
	printheap(a,n+1);
	cout<<endl<<"Sorted array in decreasing order:";
	for(int i=n;i>0;i--)
	cout<<endl<<a[i];
//	buildminheap(a,n+1);
//	cout<<endl<<"Min heap:";
//	printheap(a,n+1);
//apply algo for heaportmin;
}