
#include <iostream>
#include <string>
#include <conio.h>  // For getch()
using namespace std;

void isPalindrome(string arr) {
    string originalString = arr;
    string reversedString = "";

    // Reverse the string
    for (int j = arr.length() - 1; j >= 0; j--) {
        reversedString += arr[j];
    }

    // Compare both
    if (reversedString == originalString)
        cout << "✅ \"" << arr << "\" is a palindrome.\n";
    else
        cout << "❌ \"" << arr << "\" is not a palindrome.\n";
}

int main() {
    char choice;
    do {
        string str;
        cout << "\nEnter a word: ";
        cin >> str;
        isPalindrome(str);

        cout << "\nPress any key to continue or 'Esc' to quit...";
        choice = _getch(); //Waits for a key press 

        if (choice == 27) { // ASCII value of ESC key = 27
            cout << "\nProgram terminated by user.\n";
            break;
        }

    } while (true);

    return 0;
}