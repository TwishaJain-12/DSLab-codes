/* Write a program to find first non-repeating character in a string using Queue. 
Sample I/P: a a b c 
Sample O/P: a -1 b b
*/
#include<iostream>
#include<queue>
#include<string>
using namespace std;

void character(string s){
    queue<char>q;
    int freq[256] = {0};
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        freq[ch]++;
        q.push(ch);

        while(!q.empty() && freq[q.front()]>1){
            q.pop();
        }

        if(q.empty()) {
            cout << -1 << " ";
        } 
        else {
            cout << q.front() << " ";
        }
    }
}

int main(){
    string str = "aabc";
    character(str);
    return 0;
}