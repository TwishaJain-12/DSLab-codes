#include<iostream>
#include<string>
using namespace std;

void Binary(int n){
    for(int i=1; i<=n; i++){
        int temp = i;
        string binary={};
        while(temp>0){
            int rem = temp%2;
            if(rem==0){
                binary = binary + '0';
            }
            else{
                binary = binary + '1';
            }
            temp=temp/2;
        }

    int n = binary.length();
    for (int i = 0; i < n / 2; i++) {
        swap(binary[i], binary[n - i - 1]);
    }

    cout<<binary<<"  ";
    }
}

int main(){
    Binary(5);
    return 0;
}