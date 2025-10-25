#include<bits/stdc++.h>
using namespace std;

int countStudents(int students[], int sandwiches[], int n){
    //sandwich in stack; student in queue
    int front = 0; //front of students queue
    int rear = n-1;
    int top = 0; //top of sandwich stack
    int count = 0; //how many consecutive students refused
    int total = n; //total students remaining to be fed

    while(total>0 && count<total){
        if(students[front]==sandwiches[top]){
            //student gets the sandwich
            top++;
            total--;
            count=0; //reset count whenever a student gets a sandwich
        }
        else{
            rear=(rear+1)%n;
            students[rear] = students[front];
            count++;
        }
        front=(front+1)%n;
    }
    return total;
}

int main(){
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int n = 4;

    cout << countStudents(students, sandwiches, n);
    return 0;
}