#include <iostream>
using namespace std;


int parse_input(string myinput) {
    // parse input, return number base based off formatting
    // currently only does base-10 / decimal and base-16 / hex
    cout << "in parse_input function, myinput is: " << myinput << endl;
    return 10;
}

string convert_to_binary(string myinput, int base) {
    // converts from base-x to binary, returned as string output
    cout << "in convert_to_binary function, myinput is: " << myinput << " and base is: " << base << endl;
    return myinput;
}

int main() {
    string myinput;
    cout << "Enter a number in hex or decimal: ";
    cin >> myinput;
    parse_input(myinput);
    convert_to_binary(myinput, 10);
    
    return 0;
}
