//String Split, string:lowercase English alphabets, split in 3 substrings where one is substring of other 2
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int l=s.length();
    int freq[l];
    for(int i=0; i<l; i++){
        freq[i]=0;
    }

    int i;
    for(i=0; i<l; i++){
        for(int j=0; j<l; j++){
            if(s.at(i)==s.at(j)){
                freq[i]=freq[i]+1;
            }
        }
        if(freq[i]>=3){
            cout<<"YES"<<endl;
            break;
        }
    }
    if(i==l){
        cout<<"NO"<<endl;
    }

    return 0;
    
}