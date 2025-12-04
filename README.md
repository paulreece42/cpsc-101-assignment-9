# cpsc-101-assignment-9
 
LCC CPSC-101 Assignment 9



Instructions:

1. Install Visual Studio Code tooling for C++. I recommend following the suggestions in Setting Up C++ in Visual Studio Code with Conda, but there are many options.
2. Write a C++ file that includes the same three functions that you created in the previous assignment that will again work together, only this time they will be implemented in C++. 
    1. main() - This function starts the program, requesting either a decimal or hexadecimal input.
    2. parse_input(input) - This function determines if the string input represents an integer or a hex (hex begin with "0x").
    3. convert_to_binary(type) - This function converts the input to binary, taking into account whether the type is decimal or hexadecimal.
3. Students MUST have at least 15 commits that show iteration as one builds up the functions.

Notes:

Uses c++20, the 2020 version of C++, for the std::format() function

With miniconda, this should be no problem, just add `-std=c++20` to compile options, like so:

    clang++ -std=c++20 main.cpp -o programName
    g++ -std=c++20 main.cpp -o programName

It just won't zero-pad the hex values without that though, no big deal

Debug output can be turned on with -DDEBUG compiler flag, for example:

    clang++ -std=c++20 -DDEBUG main.cpp
    $ ./a.out
    Enter a number in hex or decimal: 0x42
    in convert_to_binary function, myinput is: 0x42 and base is: 16
    coming soon!
