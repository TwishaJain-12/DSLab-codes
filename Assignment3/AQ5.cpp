#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cout<<"Enter the no. of elements: ";
    cin>>N;
    int A[N], B[N];
    stack<int>S;
    cout<<"Enter the elements: ";
    for(int i=0; i<N; i++){
        cin>>A[i];
        B[i]=A[i];
    }

    int temp;
    for (int i = 0; i < N-1; i++) {
    for (int j = 0; j < N-i-1; j++) {
        if (B[j] > B[j+1]) {
            temp = B[j];
            B[j] = B[j+1];
            B[j+1] = temp;
        }
    }
}
    //A -> S
    //S -> B
    int k=0;
    for(int i=0; i<N; i++){
        S.push(A[i]);
        while(!S.empty() && B[k]==S.top()){
            S.pop();
            k++;
        }
    }

    if(k==N){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}