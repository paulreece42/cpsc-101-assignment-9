#include <iostream>
#include "calculator.h"
using namespace std;

int main() {
    int x = 10, y = 5;
    
    cout << "Addition: " << add(x, y) << endl;
    cout << "Subtraction: " << subtract(x, y) << endl;
    
    return 0;
}