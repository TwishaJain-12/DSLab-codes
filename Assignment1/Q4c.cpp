//Find the Transpose of a Matrix 
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
    
    //transpose
    int t[b][a];
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            t[j][i]=m[i][j];
        }
    }

    //display
    cout<<endl<<"The transposed matrix is: "<<endl;
    for(int i=0; i<b; i++){
        for(int j=0; j<a; j++){
            cout<<t[i][j]<<"  ";
        }
        cout<<endl;
    }
}