#include<iostream>
#include<string>
#include<queue>
using namespace std;

void generateBinary(int n){
    queue<string>q;
    string num = "1";
    q.push(num);
    for(int i=1; i<=n; i++){
        string num = q.front();
        cout<<num<<"  ";
        q.pop();
        q.push(num+'0');
        q.push(num+'1');
    }
}

int main(){
    generateBinary(5);
    return 0;
}