#include <iostream>
using namespace std;

int main() {
    int numbers[5];
    int sum = 0;
    
    cout << "Enter 5 numbers:\n";
    for(int i = 0; i < 5; i++) {
        cout << "Number " << (i+1) << ": ";
        cin >> numbers[i];
        sum += numbers[i];
    }
    
    cout << "\nYou entered: ";
    for(int i = 0; i < 5; i++) {
        cout << numbers[i] << " ";
    }
    
    double average = sum / 5.0;
    cout << "\nSum: " << sum << endl;
    cout << "Average: " << average << endl;
    
    return 0;
}

