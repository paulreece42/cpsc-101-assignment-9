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

Can build using g++ / clang++, or cmake

    clang++ main.cpp -o programName
    g++ main.cpp -o programName


cmake:

	bash-3.2$ mkdir build
	bash-3.2$ cd build/
	bash-3.2$ cmake ..
	-- The CXX compiler identification is AppleClang 17.0.0.17000404
	-- Detecting CXX compiler ABI info
	-- Detecting CXX compiler ABI info - done
	-- Check for working CXX compiler: /usr/bin/c++ - skipped
	-- Detecting CXX compile features
	-- Detecting CXX compile features - done
	-- Configuring done (0.4s)
	-- Generating done (0.0s)
	-- Build files have been written to: /Users/preece/CPP_CPSC_101/build
	bash-3.2$ make
	[ 50%] Building CXX object CMakeFiles/cpsc-101-assignment-9.dir/main.cpp.o
	[100%] Linking CXX executable cpsc-101-assignment-9
	[100%] Built target cpsc-101-assignment-9
	bash-3.2$ ./cpsc-101-assignment-9
	Enter a number in hex or decimal: 0x42
	0100 0010
	bash-3.2$ ./cpsc-101-assignment-9
	Enter a number in hex or decimal: 0xFF
	1111 1111
	bash-3.2$


Debug output can be turned on with -DDEBUG compiler flag, for example:

    clang++ -std=c++20 -DDEBUG main.cpp
    $ ./a.out
    Enter a number in hex or decimal: 0x42
    in convert_to_binary function, myinput is: 0x42 and base is: 16
    coming soon!
