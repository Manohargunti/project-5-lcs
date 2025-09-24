#include <iostream>
#include <string.h>   // for strlen()
using namespace std;

int main() {
    // Get two strings from the user
    char firstString[100], secondString[100];
    cout << "Enter first string: ";
    cin >> firstString;
    cout << "Enter second string: ";
    cin >> secondString;

    // Find lengths of both strings
    int lengthFirst = strlen(firstString);
    int lengthSecond = strlen(secondString);

    // As given in assignment, both strings should have the same size
    if (lengthFirst != lengthSecond) {
        cout << "Strings must be of identical length.\n";
        return 0;  // stop program if sizes are different
    }

    // Table to store results step by step
    // lookupTable[row][col] shows the length of common part
    // that ends at firstString[row-1] and secondString[col-1]
    int lookupTable[101][101];

    // Variables to keep track of the answer
    int longestLength = 0;     // biggest common part length
    int lastIndexFirst = 0;    // position in first string where it ends

    // Start the table with zeros
    for (int row = 0; row <= lengthFirst; row++) {
        for (int col = 0; col <= lengthSecond; col++) {
            lookupTable[row][col] = 0;
        }
    }

    // Fill the table using rules of longest common substring
    for (int row = 1; row <= lengthFirst; row++) {
        for (int col = 1; col <= lengthSecond; col++) {
            if (firstString[row - 1] == secondString[col - 1]) {
                // If letters are same, increase from top-left diagonal
                lookupTable[row][col] = lookupTable[row - 1][col - 1] + 1;

                // Update longest length and ending position
                if (lookupTable[row][col] > longestLength) {
                    longestLength = lookupTable[row][col];
                    lastIndexFirst = row - 1;
                }
            } else {
                // If letters are different, set value to 0
                lookupTable[row][col] = 0;
            }
        }
    }

    // Show the lookup table
    cout << "\nDP Lookup Table:\n   ";
    for (int col = 0; col < lengthSecond; col++) {
        cout << secondString[col] << " ";
    }
    cout << "\n";

    for (int row = 1; row <= lengthFirst; row++) {
        cout << firstString[row - 1] << " ";
        for (int col = 1; col <= lengthSecond; col++) {
            cout << lookupTable[row][col] << " ";
        }
        cout << "\n";
    }

    // Show the longest common substring
    cout << "\nLongest Common Substring: ";
    for (int i = lastIndexFirst - longestLength + 1; i <= lastIndexFirst; i++) {
        cout << firstString[i];
    }
    cout << " (Length = " << longestLength << ")\n";

    return 0;  // end program
}
