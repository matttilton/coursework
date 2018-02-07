//Matthew Tilton
#include <iostream>
using namespace std;

void firstInvestigationFunction2(int x[]);

void firstInvestigation() {
    int testArray[] = {1,2,3,4,5,6,7,8,9,0};

    cout << "Pointer to array in function 1: ";
    cout << testArray << endl;

    firstInvestigationFunction2(testArray);
}

void firstInvestigationFunction2(int x[]) {
    cout << "Pointer to array in function 2: ";
    cout << x << endl;
}

void secondInvestigation() {
    int x = 0;
    int y = 0;
    cout << x << ", " << y << endl;
    {
        int x = 1;
        y = 1;
        {
            int x = 2;
            y = 2;
        }
    }
    cout << x << ", " << y << endl;
}

void thirdInvestigation() {
    int count = 0;
    
    test2:
    if (count <= 1) {
        count = count + 1;
        goto test;
    }
    return;
    test:
        cout << "goto" << endl;
        goto test2;
}

int main() {
    cout << "First Investigation" << endl;
    firstInvestigation();
    cout << "Pointers are the same. Arrays cannot be passed by value in c++ but you can create a copy then pass the copy." << endl;
    cout << "Second Investigation" << endl;
    secondInvestigation();
    cout << "Variables can be accessed from parent scope if you dont redeclare the datatype." << endl;
    cout << "Third Investigation" << endl;
    thirdInvestigation();
    cout << "goto statements do work in c++. you goto a label in the form \"label:\"" << endl;
    return 0;
}