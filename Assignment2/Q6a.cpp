//Sparse Matrix: TRANSPOSE
#include<iostream>
using namespace std;
int main(){
    int r,c,nz=0;
    cout<<"Enter the no. of rows in the matrix: ";
    cin>>r;
    cout<<"Enter the no. of columns in the matrix: ";
    cin>>c;
    int m[r][c];
    cout<<"Enter the matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<"Row "<<i+1<<" Column "<<j+1<<": ";
            cin>>m[i][j];
            if(m[i][j]!=0){
                nz++;
            }
        }
    }
    int t[nz][3], tt[nz][3];
    int k=0;
    cout<<endl<<"The matrix is: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<m[i][j]<<"  ";
            if(m[i][j]!=0){
                t[k][0]=i;
                t[k][1]=j;
                t[k][2]=m[i][j];
                k++;
            }
        }
        cout<<endl;
    }
    cout<<endl;

    //print sparse
    cout<<"Sparse matrix is: "<<endl;
    for(int i=0; i<nz; i++){
        cout<<t[i][0]<<"  "<<t[i][1]<<"  "<<t[i][2]<<endl;
    }

    cout<<endl<<"The transpose of sparse matrix is: "<<endl;
    k=0;
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            if(m[j][i]!=0){
                tt[k][0]=i;
                tt[k][1]=j;
                tt[k][2]=m[j][i];
                cout<<tt[k][0]<<"  "<<tt[k][1]<<"  "<<tt[k][2]<<endl; //transpose sparse
                k++;
            }
        }
    }

    return 0;
}