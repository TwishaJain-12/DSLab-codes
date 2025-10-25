#include<bits/stdc++.h>
using namespace std;

bool queueSorting(int n, queue<int>&input){
    stack<int>st;
    int expected=1;
    int fr;

    while(!input.empty()){
        fr = input.front();
        input.pop();

        if(fr == expected){
            expected++;
        }
        else{
            if(st.empty()){
                st.push(fr);
            }
            else if(!st.empty() && fr>st.top()){
                return false;
            }
            else{
                st.push(fr);
            }
        }
    }

    while(!st.empty() && st.top()==expected){
        st.pop();
        expected++;
    }

    if(expected-1==n && st.empty()){
        return true;
    }

    return false;
}

int main(){
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(6);
    q.push(3);
    q.push(4);

    (queueSorting(6,q) ? (cout<<"Yes"):(cout<<"No"));
    return 0;
}