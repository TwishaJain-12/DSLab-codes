//Upper Triangular matrix 
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the order of the upper-diagnol matrix: ";
    cin>>n;
    int m[n][n];
    cout<<"Enter the matrix: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<"Row "<<i+1<<" Column "<<j+1<<": ";
            cin>>m[i][j];
        }
    }
    cout<<endl<<"The matrix is: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<m[i][j]<<"  ";
        }
        cout<<endl;
    }

    int a[n*(n+1)/2], k=0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            a[k]=m[i][j];
            k++;
        }
    }

    cout<<"The 1D array is: ";
    for(int i=0; i<k; i++){
        cout<<a[i]<<"  ";
    }

    return 0;
}