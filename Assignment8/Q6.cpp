#include<iostream>
using namespace std;
int arr[100];
int k=1;
void maxheapify(int n)
{
	int left=n*2;
	int right=n*2+1;
	int largest=n;
	if(left<=k&&arr[left]>arr[largest])
	largest=left;
	else
	largest=n;
	if(right<=k&&arr[right]>arr[largest])
	largest=right;
	if(largest!=n)
	{
		int temp=arr[largest];
		arr[largest]=arr[n];
		arr[n]=temp;
		maxheapify(largest);
	}
}
void buildheap()
{
	for(int i=k/2;i>0;i--)
	maxheapify(i);
}
void insert(int n)
{
	arr[k]=n;
	buildheap();
	k++;
}
int extractmax()
{
	if(k>1)
	{
	int temp=arr[1];
	arr[1]=arr[k-1];
	arr[k-1]=temp;
	k--;
	buildheap();
	return temp;
    }
    else
    return -1;
}
void maximum()
{
	if(k>1)
	{
	cout<<endl<<"Maximum of the priority queues is:";
	cout<<arr[1]<<endl;
    }
    else
    cout<<endl<<"No element present";
}
void increment(int f,int g)
{
	arr[f]=g;
	buildheap();
}
void printheap()
{
	cout<<endl<<"Priority Queue:";
	for(int i=1;i<k;i++)
	cout<<endl<<arr[i];
}
int main()
{
	int c=1,ch=1,x,d;
	arr[0]=-1;
	while(ch>=1&&ch<=5)
	{
		cout<<endl<<"What operation to perform:"<<endl;
		cout<<"1-> Insert a key"<<endl;
		cout<<"2-> Extract Max"<<endl;
		cout<<"3-> Maximum"<<endl;
		cout<<"4-> Increment the key"<<endl;
		cout<<"5-> Print the heap"<<endl;
		cout<<"0-> Exit"<<endl;
	    cout<<"Enter the choice:";
	    cin>>ch;
	    if(ch==1)
	    {
	    	cout<<endl<<"Enter the value:";
	    	cin>>x;
	    	insert(x);
	    	c++;
		}
		else if(ch==2)
		{
			int y=extractmax();
			c--;
			cout<<endl<<"Maximum value extracted="<<y;
		}
		else if(ch==3)
		{
			maximum();
		}
		else if(ch==4)
		{
			int i;
			cout<<"Enter the value which has to be incremented:";
			cin>>d;
			for(i=1;i<c;i++)
			{
				if(arr[i]==d)
				break;
			}
			cout<<"Now enter the incremented value:";
			cin>>x;
			increment(i,x);
		}
		else if(ch==5)
		printheap();
		else
		break;
    }
    return 0;
}