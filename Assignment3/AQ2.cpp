//supports getMin() in O(1) TC and SC
#include<iostream>
#include<stack>
using namespace std;
class SpecialStack{
    stack <int> s;
    int minEle;
    public:
        void push(int x){
            if(s.empty()){
                s.push(x);
                minEle = x;
            }
            else if(x>=minEle){
                s.push(x);
            }
            else{
                s.push(2*x-minEle); //minEle -> previous min //stores a hint of previous minEle
                minEle=x; //newMin //updated min
            }
        }

        void pop(){
            if(s.empty()){
                cout<<"Underflow Condition, stack is empty!"<<endl;
                return;
            }
            else if(s.top()>=minEle){
                cout<<s.top()<<" has been deleted!"<<endl;
                s.pop();
            }
            else{
                //stackEle actual ele nhi hain=> minEle delete ho rha, now minEle shd point to preMin
                cout<<minEle<<" has been deleted!"<<endl;
                minEle = 2*minEle - s.top(); //updated to preMin which lies in left of the stack
                s.pop();
            }
        }

        void peek(){
            if(s.empty()){
                cout<<"The stack is empty!"<<endl;
                return;
            }
            else if(s.top()>=minEle){
                cout<<"Top Element: "<<s.top()<<endl;
            }
            else{
                cout<<"Top Element: "<<minEle<<endl;
            }
        }

        void getMin(){
            if(s.empty()){
                cout<<"The stack is empty!"<<endl;
            }
            else{
                cout<<"The Minimum Element: "<<minEle<<endl;
            }
        }
};
// int checkMin(int x, int Min){
//     if(x<Min){
//         return (x);
//     }
//     else{
//         return Min;
//     }
// }
// void getMin(int Min){
//     cout<<"The minimum element in the Stack is: "<<Min<<endl;
// }

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
            // if(S.empty()){
            //     S.push(x);
            //     min = x;
            // }
            // else{
            //     min = checkMin(x, min);
            //     S.push(x);
            // }
            st.push(x);
            break;
        
        case 2:
        // cout<<S.top()<<" has been deleted!"<<endl;
        // S.pop();
        st.pop();
        break;

        case 3:
        // cout<<"The topmost element is: "<<S.top()<<endl;
        st.peek();
        break;

        case 4:
        // getMin(min);
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

