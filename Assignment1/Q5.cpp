//Write a program to find sum of every row and every column in a two-dimensional array
#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the number of rows in the first matrix: ";
	cin>>a;
	cout<<"Enter the number of columns in the first matrix: ";
	cin>>b;
	
	int m[a][b];
    //INPUT
    cout<<"\nEnter the matrix: ";
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                cout<<"Enter the element of row "<< i+1<<", column "<<j+1<<": ";
                cin>>m[i][j];
            }
        }
    
    cout<<endl;

    //sum of row
    for(int i=0; i<a; i++){
        int sr=0;
        for(int j=0; j<b; j++){
            sr = sr + m[i][j];
        }
        cout<<"The sum of elements of "<<i+1<<" row is: "<<sr<<endl;
    }

    cout<<endl;

    //sum of column
    for(int i=0; i<b; i++){
        int sc=0; //here my i=column of m & j=row of m
        for(int j=0; j<a; j++){
            sc = sc + m[j][i];
        }
        cout<<"The sum of elements of "<<i+1<<" column is: "<<sc<<endl;
    }
}