//majority element
#include <bits/stdc++.h>
using namespace std;
int findMajorityElement(int arr[], int n) {
    sort(arr, arr+n);

    //potential majority element
    int candidate = arr[n/2];
	int count=0;
	for(int i=0; i<n; i++){
		if(arr[i]==candidate){
			count++;
		}
	}
	if(count>n/2) return candidate;
	return -1;
}

int main(){
    int n; 
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"The majority element is: "<<findMajorityElement(arr, n)<<endl;
    return 0;
}