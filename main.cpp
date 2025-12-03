#include <iostream>
#include <regex> // holy cow guys! C++11 got regex! Finally! :-D
using namespace std;



int parse_input(string myinput) {
    // parse input, return number base based off formatting
    // currently only does base-10 / decimal and base-16 / hex
    #ifdef DEBUG
        cout << "in parse_input function, myinput is: " << myinput << endl;
    #endif
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
    #ifdef DEBUG
       cout << "in convert_to_binary function, myinput is: " << myinput << " and base is: " << base << endl;
    #endif
    if (base == 16) {
        return "coming soon!";
    }
    else {
        int int_myinput = stoi(myinput);
        int myint = (int)int_myinput / 2;
        int remainder = int_myinput % 2;
        #ifdef DEBUG
            cout << "myint: " << myint << " remainder: " << remainder << endl;
        #endif
        while (myint > 0 || remainder > 0) {
            myoutput = to_string(remainder) + myoutput;
            remainder = myint % 2;
            myint = (int)myint / 2;
        }
        return myoutput;
    }
}

int main() {
    string myinput;
    cout << "Enter a number in hex or decimal: ";
    cin >> myinput;
    cout << convert_to_binary(myinput, parse_input(myinput)) << endl;
    
    return 0;
}
