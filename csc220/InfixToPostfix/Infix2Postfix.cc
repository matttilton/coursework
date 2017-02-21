#include <iostream>
// #include <>
// #include <>
using namespace std;

bool IsOp(char ch);

int main() {
    char input[1024];
    while(cin.getline(input, 1024)) {
        for(int i = 0; i <= 1; i++){
            cout << IsOp(input[i]) << endl;
        }
    }
    return 0;

};

bool IsOp(char data) {
    return (data < '0' || data > '9');
}
