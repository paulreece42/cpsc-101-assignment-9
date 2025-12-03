#include <iostream>
#include <regex> // holy cow guys! C++11 got regex! Finally! :-D
using namespace std;


int parse_input(string myinput) {
    // parse input, return number base based off formatting
    // currently only does base-10 / decimal and base-16 / hex
    regex pattern("^0x");
    smatch match;
    if (regex_search(myinput, match, pattern)) {
        return 16;
    }
    else {
        return 10;
    }
}

string convert_to_binary(string myinput, int base) {
    // converts from base-x to binary, returned as string output
    string myoutput;
    myoutput = "in convert_to_binary function, myinput is: " + myinput + " and base is: " + to_string(base);
    return myoutput;
}

int main() {
    string myinput;
    cout << "Enter a number in hex or decimal: ";
    cin >> myinput;
    cout << convert_to_binary(myinput, parse_input(myinput)) << endl;
    
    return 0;
}
