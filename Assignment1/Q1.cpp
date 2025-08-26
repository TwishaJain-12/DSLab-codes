#include<iostream>
using namespace std;
int arr[100]; //declared global arr
int n; //size of array
int menu;

//function prototypes
void displayMenu();
void createArr(int arr[], int &n);
void displayArr(int arr[], int &n);
void insertArr(int arr[], int &n);
void deleteArr(int arr[], int &n);
void linearSearch(int arr[], int &n);

int main(){
    
    
    displayMenu();
    char input;

    switch(menu){
        case 1: //create
            createArr(arr, n);
            break;
        
        case 2: //display
            cout<<"Has array been created(Y/N): ";
            cin>>input;
            if(input=='Y'){
                displayArr(arr, n);
            }
            else{
                createArr(arr, n);
                displayArr(arr, n);
            }
            break;
        
        case 3: //insert
            cout<<"Has array been created(Y/N): ";
            cin>>input;
            if(input=='Y'){
                insertArr(arr, n);
            }
            else{
                createArr(arr, n);
                displayArr(arr, n);
                insertArr(arr, n);
            }
            break;

        case 4: //delete
            cout<<"Has array been created(Y/N): ";
            cin>>input;
            if(input=='Y'){
                deleteArr(arr, n);
            }
            else{
                createArr(arr, n);
                displayArr(arr, n);
                deleteArr(arr, n);
            }
            break;

        case 5: //linear search
            cout<<"Has array been created(Y/N): ";
            cin>>input;
            if(input=='Y'){
                linearSearch(arr, n);
            }
            else{
                createArr(arr, n);
                linearSearch(arr, n);
            }
            break;
        
        case 6: 
            cout<<"The program has been exited";
    }

    return 0;
}

void displayMenu(){
    cout<<"MENU to demonstrate the following operations of Arrays : "<<endl<<"1. Create"<<endl<<"2. Display"<<endl<<"3. Insert"<<endl<<"4. Delete"<<endl<<"5. Linear Search"<<endl<<"6. Exit"<<endl;
    cout<<"Choose an option and enter the number: ";
    cin>>menu;
}

void createArr(int arr[], int &n){
    cout<<endl;
    cout<<"Enter the number of elements in your array: ";
    cin>>n;
    cout<<endl;
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
}

void displayArr(int arr[], int &n){
    cout<<endl;
    cout<<"The created array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void insertArr(int arr[], int &n){
    cout<<endl;
    int pos1, e1;
    cout<<"Enter the element to be inserted in the array: ";
    cin>>e1;
    cout<<"Enter the position at which it should be inserted: ";
    cin>>pos1;
    for(int i=n; i>=pos1-1; i--){
        arr[i+1]=arr[i];
    }
    arr[pos1-1]=e1;
    n++;
    cout<<"The new array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void deleteArr(int arr[], int &n){
    cout<<endl;
    int pos2, e2;
    cout<<"Enter the element to be deleted in the array: ";
    cin>>e2;
    cout<<"Enter the position at which it should be deleted: ";
    cin>>pos2;
    for(int i=pos2-1;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;
    cout<<"The new array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void linearSearch(int arr[], int &n){
    cout<<endl;
    int e3, pos3;
    cout<<"Enter the element to be searched: ";
    cin>>e3;
    for(int i=0; i<n; i++){
        if(arr[i]==e3){
            pos3=i;
            cout<<"The element has been found at position "<<(pos3+1)<<endl;
            break;
        }
        if(i==n){
            cout<<"The element was not found!";
        }
    }
}
