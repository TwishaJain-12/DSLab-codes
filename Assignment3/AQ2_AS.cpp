//AQ2 with Auxillary Stack
#include<iostream>
#include<stack>
using namespace std;
class SpecialStack{
    stack<int>S;
    stack<int>AS;
    public: 
        void push(int x){
            S.push(x);
            if(AS.empty() || x<AS.top()){
                AS.push(x);
            }
            else{
                AS.push(AS.top());
            }
        }

        void pop(){
            if(S.empty()){
                cout<<"The stack is empty!"<<endl;
                return;
            }
            else{
                cout<<S.top()<<" has been deleted."<<endl;
                S.pop();
                AS.pop();
            }
        }

        void peek(){
            if(S.empty()){
                cout<<"The stack is empty!"<<endl;
                return;
            }
            else{
                cout<<S.top()<<" is the Top Element!"<<endl;
            }
        }

        void getMin(){
            if(AS.empty()){
                cout<<"The stack is empty. No minimum element for an empty stack."<<endl;
                return;
            }
            else{
                cout<<"Minimum Element: "<<AS.top()<<endl;
            }
        }
};

int main(){
    SpecialStack st;
    int n, x;
    do{
        cout<<"Enter the no. for: 1. push  2. pop  3. peek  4. getMin() 5. Exit"<<endl;
        cin>>n;
        switch (n)
        {
        case 1:
        cout<<"Enter the integer: ";
        cin>>x;
        st.push(x);
        break;
        
        case 2:
        st.pop();
        break;

        case 3:
        st.peek();
        break;

        case 4:
        st.getMin();
        break;
        
        case 5:
        cout<<"The program has been exited!"<<endl;
        break;

        default:
        cout<<"Error!"<<endl;
        break;
        }
    }while(n<5);

    return 0;
}