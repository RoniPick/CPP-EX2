#include <iostream>
#include <string>
#include <stdlib.h>
#include "mat.hpp"

using namespace std;
using namespace ariel;

int main() {

    int row;
    int col;
    char c1;
    char c2;

    cout << "Please enter positive odd row number" << endl;
    cin >> row;
    cout << "Please enter positive odd column number" << endl;
    cin >> col;
    cout << "Please enter first char" << endl;
    cin >> c1;
    cout << "Please enter second char" << endl;
    cin >> c2;

    try{
        cout << mat(col, row, c1, c2);
    }

    catch(exception& ex){
        cout << "Wrong input, "  << ex.what() << endl;
    }


    return 0;
}
