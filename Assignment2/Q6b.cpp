// Sparse Matrix: ADDITION
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
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << ": ";
            cin >> m1[i][j];
            if (m1[i][j] != 0)
            {
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
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << "Row " << i + 1 << " Column " << j + 1 << ": ";
            cin >> m2[i][j];
            if (m2[i][j] != 0)
            {
                nz2++;
            }
        }
    }
    // sp1
    int t1[nz1+1][3];
    int k = 1;
    cout << endl
         << "The matrix1 is: " << endl;
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            cout << m1[i][j] << "  ";
            if (m1[i][j] != 0)
            {
                t1[k][0] = i;
                t1[k][1] = j;
                t1[k][2] = m1[i][j];
                k++;
            }
        }
        cout << endl;
        t1[0][0]=r1;
        t1[0][1]=c1;
        t1[0][2]=nz1;
    }
    // sp2
    int t2[nz2+1][3];
    k = 1;
    cout << endl
         << "The matrix2 is: " << endl;
    for (int i = 0; i < r2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            cout << m2[i][j] << "  ";
            if (m2[i][j] != 0)
            {
                t2[k][0] = i;
                t2[k][1] = j;
                t2[k][2] = m2[i][j];
                k++;
            }
        }
        cout << endl;
    }
    cout << endl;
    t2[0][0]=r2;
    t2[0][1]=c2;
    t2[0][2]=nz2;
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

    int i = 1, j = 1, t3[100][3];
    k = 1;
    while (i <= nz1 && j <= nz2)
    {
        if (t1[i][0] == t2[j][0] && t1[i][1] == t2[j][1])
        {
            t3[k][0] = t1[i][0];
            t3[k][1] = t1[i][1];
            t3[k][2] = t1[i][2] + t2[j][2];
            k++;
            i++;
            j++;
        }
        else if (t1[i][0] < t2[j][0] || (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1]))
        {
            t3[k][0] = t1[i][0];
            t3[k][1] = t1[i][1];
            t3[k][2] = t1[i][2];
            k++;
            i++;
        }
        else
        {
            t3[k][0] = t2[j][0];
            t3[k][1] = t2[j][1];
            t3[k][2] = t2[j][2];
            k++;
            j++;
        }
    }
    for (; i < nz1; i++)
    {
        t3[k][0] = t1[i][0];
        t3[k][1] = t1[i][1];
        t3[k][2] = t1[i][2];
        k++;
    }
    for (; j < nz2; j++)
    {
        t3[k][0] = t2[j][0];
        t3[k][1] = t2[j][1];
        t3[k][2] = t2[j][2];
        k++;
    }
    t3[0][0]=r1;
    t3[0][1]=c1;
    t3[0][2]=k-1;

    cout << "Sparse matrix for addition of 1 & 2 is: " << endl;
    for (int i = 0; i <= k; i++)
    {
        cout << t3[i][0] << "  " << t3[i][1] << "  " << t3[i][2] << endl;
    }

    return 0;
}