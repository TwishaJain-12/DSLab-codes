/* Write a program interleave the first half of the queue with second half.
Sample I/P: 4 7 11 20 5 9 
Sample O/P: 4 20 7 5 11 9
*/
#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>q1;
    queue<int>q2;
    queue<int>q3;
    bool flag=1;
    while(flag){
        int menu, x;
        cout<<"1: Insert an element in queue"<<endl<<"2. Stop"<<endl<<"Select: ";
        cin>>menu;
        switch (menu)
        {
        case 1:
            cout<<"Enter the element to be pushed: ";
            cin>>x;
            q1.push(x);
            break;
        
        default:
            cout<<"Insertion completed"<<endl;
            flag=0;
            break;
        }
    }
    int size=q1.size();
    for(int i=0; i<size/2; i++){ //first half of q1 -> in q2
        q2.push(q1.front());
        q1.pop();
    }
    for(int i=0; i<size/2; i++){ //interleave q2 with q1
        cout<<q2.front()<<"\t";
        q2.pop();
        cout<<q1.front()<<"\t";
        q1.pop();

        // q3.push(q2.front());
        // q2.pop();
        // q3.push(q1.front());
        // q1.pop();
    }

    //if no. of elements in queue are odd => q1 wont be empty
    while(!q1.empty()){
        cout<<q1.front()<<"\t";
        q1.pop();
    }
    cout<<endl;

    return 0;
}