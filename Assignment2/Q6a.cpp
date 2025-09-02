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
    int t[nz+1][3], tt[nz+1][3];
    int k=1;
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
    t[0][0]=r;
    t[0][1]=c;
    t[0][2]=nz;

    //print sparse
    cout<<"Sparse matrix is: "<<endl;
    for(int i=0; i<=nz; i++){
        cout<<t[i][0]<<"  "<<t[i][1]<<"  "<<t[i][2]<<endl;
    }

    int j=0;
    k=1;
    while(j<c){
        for(int i=1; i<=nz; i++){
            if(t[i][1]==j){
                tt[k][0]=t[i][1]; //col
                tt[k][1]=t[i][0]; //row
                tt[k][2]=t[i][2]; //val
                k++;
            }
        }
        j++;
    }
    tt[0][0]=r;
    tt[0][1]=c;
    tt[0][2]=nz;
    cout<<endl<<"The transpose of sparse matrix is: "<<endl;
    for(int i=0; i<=nz; i++){
        cout<<tt[i][0]<<"  "<<tt[i][1]<<"  "<<tt[i][2]<<endl;
    }
    return 0;
}