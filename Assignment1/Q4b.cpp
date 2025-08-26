#include<iostream>
using namespace std;
int main(){
    int a, b, c, d;
	cout<<"Enter the number of rows in the first matrix: ";
	cin>>a;
	cout<<"Enter the number of columns in the first matrix: ";
	cin>>b;
	
	int m[a][b];
    
    cout<<"\nEnter the number of rows in the second matrix: ";
	cin>>c;
	cout<<"Enter the number of columns in the second matrix: ";
	cin>>d;
	
	int n[c][d];
	
    
    if(b==c){
        //input 1st matrix
        cout<<"\nEnter the first array: ";
        for(int i=0; i<a; i++){
            for(int j=0; j<b; j++){
                cout<<"Enter the element of row "<< i+1<<", column "<<j+1<<": ";
                cin>>m[i][j];
            }
        }
        
        //input 2nd matrix
        cout<<"\nEnter the second array: ";
        for(int i=0; i<c; i++){
            for(int j=0; j<d; j++){
                cout<<"Enter the element of row "<< i+1<<", column "<<j+1<<": ";
                cin>>n[i][j];
            }
        }
        //defined result matrix o
        int o[a][d];

        for(int i=0; i<a; i++){
            for(int j=0; j<d; j++){
                int sum=0;
                for(int k=0; k<b; k++){
                    sum=sum+ m[i][k]*n[k][j];
                }
                o[i][j]=sum;
            }
        }

        //output
        cout<<"The result of matrix multiplication is: "<<endl;
        for(int i=0; i<a; i++){
            for(int j=0; j<d; j++){
                cout<< o[i][j] <<"  ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"The matrices aren't of correct order, try again!";
    }

}