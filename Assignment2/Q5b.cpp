//Tri-diagnol matrix
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the order of the tri-diagnol matrix: ";
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

    int a[3*n-2];
    for(int i=0; i<n; i++){
        a[3*i]=m[i][i]; //diagnol elements
    }
    for(int i=0; i<n-1; i++){
        a[3*i+1]=m[i][i+1]; //upper-diagnol
        a[3*i+2]=m[i+1][i]; //lower-diagnol
    }

    cout<<"The 1D array is: ";
    for(int i=0; i<3*n-2; i++){
        cout<<a[i]<<"  ";
    }

    return 0;
}