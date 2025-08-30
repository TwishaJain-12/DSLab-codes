// Sparse Matrix: MULTIPLICATION
#include <iostream>
using namespace std;
int main()
{
    int r1, c1, nz1 = 0, r2, c2, nz2 = 0;
    // matrix1
    cout << "Enter the no. of rows in matrix1: ";
    cin >> r1;
    cout << "Enter the no. of columns in matrix1: ";
    cin >> c1;
    int m1[r1][c1];
    cout << "Enter the matrix1: " << endl;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cout << "Row " << i + 1 << " Column " << j + 1 << ": ";
            cin >> m1[i][j];
            if (m1[i][j] != 0){
                nz1++;
            }
        }
    }
    // matrix2
    cout << "Enter the no. of rows in matrix2: ";
    cin >> r2;
    cout << "Enter the no. of columns in matrix2: ";
    cin >> c2;
    int m2[r2][c2];
    cout << "Enter the matrix2: " << endl;
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            cout << "Row " << i + 1 << " Column " << j + 1 << ": ";
            cin >> m2[i][j];
            if (m2[i][j] != 0){
                nz2++;
            }
        }
    }
    // sp1
    int t1[nz1+1][3];
    int k = 1;
    cout << endl<< "The matrix1 is: " << endl;
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c1; j++){
            cout << m1[i][j] << "  ";
            if (m1[i][j] != 0){
                t1[k][0] = i;
                t1[k][1] = j;
                t1[k][2] = m1[i][j];
                k++;
            }
        }
        cout << endl;
    }
    t1[0][0]=r1;
    t1[0][1]=c1;
    t1[0][2]=nz1;
    // sp2
    int t2[nz2+1][3];
    k = 1;
    cout << endl<< "The matrix2 is: " << endl;
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            cout << m2[i][j] << "  ";
            if (m2[i][j] != 0){
                t2[k][0] = i;
                t2[k][1] = j;
                t2[k][2] = m2[i][j];
                k++;
            }
        }
        cout << endl;
    }
    t2[0][0]=r2;
    t2[0][1]=c2;
    t2[0][2]=nz2;
    cout << endl;
    // print sparse 1 & 2
    cout << "Sparse matrix 1 is: " << endl;
    for (int i = 0; i <= nz1; i++)
    {
        cout << t1[i][0] << "  " << t1[i][1] << "  " << t1[i][2] << endl;
    }
    cout << "Sparse matrix 2 is: " << endl;
    for (int i = 0; i <= nz2; i++)
    {
        cout << t2[i][0] << "  " << t2[i][1] << "  " << t2[i][2] << endl;
    }
    //transpose of sp2
    int tt2[nz2+1][3];
    cout<<endl<<"The transpose of sparse matrix 2 is: "<<endl;
    int j=0;
    k=1;
    while(j<c2){
        for(int i=1; i<=nz2; i++){
            if(t2[i][1]==j){
                tt2[k][0]=t2[i][1]; //col
                tt2[k][1]=t2[i][0]; //row
                tt2[k][2]=t2[i][2]; //val
                k++;
            }
        }
        j++;
    }
    tt2[0][0]=r2;
    tt2[0][1]=c2;
    tt2[0][2]=nz2;
    
    //matrix multiplication
    int t3[30][3];
    for(int a=0; a<30; a++){
        t3[a][2]=0; //initialized all the vals of t3 to be zero.
    }
    k = 1;
    for(int i=1; i<=nz1; i++){
        for(int j=1; j<=nz2; j++){
            if(t1[i][1]==tt2[j][1]){
                bool found = false;
                    for(int x=1; x<k; x++){
                        if(t3[x][0]==t1[i][0] && t3[x][1]==tt2[j][0]){
                            t3[x][2] += t1[i][2]*tt2[j][2];
                            found = true;
                            break;
                        }
                    }
                if(!found){
                    t3[k][0]=t1[i][0];
                    t3[k][1]=tt2[j][0];
                    t3[k][2]=t1[i][2]*tt2[j][2];
                    k++;
                }
            }
        }
    }
    t3[0][0]=r1;
    t3[0][1]=c2;
    t3[0][2]=k-1;

    cout << "Sparse matrix for multiplication of matrices 1 & 2 is: " << endl;
    for (int i = 0; i < k; i++)
    {
        cout << t3[i][0] << "  " << t3[i][1] << "  " << t3[i][2] << endl;
    }

    return 0;
}