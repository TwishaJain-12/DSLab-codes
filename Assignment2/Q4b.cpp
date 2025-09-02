#include <iostream>
using namespace std;

int main() {
    char str[100];
    int len = 0;

    cout << "Enter a string: ";
    cin.getline(str, 100);
    
    while (str[len] != '\0') {
        len++;
    }

    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    cout << "Reversed string: " << str << endl;
    return 0;
}
