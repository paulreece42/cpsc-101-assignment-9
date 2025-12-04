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
        int myint; // have to declare the variables here, outside scope of the for loop
        int mybin;
        // first, remove the leading 0x
        myinput = myinput.substr(2);
        // now loop over chars
        for (char c : myinput) {
            /** These "char" character objects are actually integers, in disguise!
             *  so to save some space, we can "map" A-F to the integers 10-15 
             *  but first, force uppercase for simplification of ASCII-mapping
             *  because A = 65 in ASCII, but a = 97
             *  
             *  This will make a lot more sense if you Google "ASCII chart", probably 
             */
            c = toupper(c);
            if ( c > 47 && c < 58 ) { // 48 is 0 in ASCII, 57 is 9. So, "if 0-9"
                /** we could just cast this from a char back to a string and use
                *  stoi() or string-to-integer, since there's already a function
                *  to cast ASCII numbers 0-9 string to integer
                * but since we're already messing with ASCII, I'll just do it the same way
                */
                myint = (int)c - 48;
                
            }
            else if ( c > 64 && c < 71 ) { // 65=A, 70=F. So, "if A-F"
                // here's where we do the trick, subtract 55 from the ASCII value
                // of A-F, mapping 65-70 to 10-15
                myint = (int)c - 55;
            }
            else { // invalid hex, throw an error and die
                cout << "Flagrant System Error: invalid hex entered!" << endl;
                cout << "Program over = very yes :-(" << endl;
                /** exit code > 0 means the program exited abnormally, i.e. errored out
                *   this is important for shell scripts that often check the exit code or
                *   return value of a program, to know if the program ran successfully or not
                */
                exit(1);
            }
            // now myint is equal to a decimal integer 0-15
            #ifdef DEBUG
                cout << myint << endl;
            #endif
            /* I already wrote the code to do decimal-to-binary, no need to repeat it!
            *  Yep. We're calling our function, from within the same function, 
            * this is called a "recursive function"
            */
            mybin = stoi(convert_to_binary(to_string(myint), 10));
            /* now we have the integer representation of the binary, but for 2, that's 10
            * I want to zero-pad it with leading zeros, because it makes more sense that way, with Hex
            *
            * however, std::format seems to only be supported on c++20 and up, and on my Mac with
            * miniconda, clang seems to default to c++17 (but supports c++20)
            * I can do it with setw and stuff but let's just settle for simpler output, on older versions
            */
            #if __cplusplus >= 202002L
                myoutput += format("{:04} ", mybin);
            # else
                myoutput += to_string(mybin) + " ";
            # endif
        }
        return myoutput;
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
