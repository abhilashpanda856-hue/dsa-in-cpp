#include <iostream>
#include <string>
#include <cctype> 
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        //  The Broken Tile Filter (Left Inspector)
        // If it is NOT a letter or number, skip it
        if (!isalnum(s[left])) {
            left++;
        }
        //  The Broken Tile Filter (Right Inspector)
        else if (!isalnum(s[right])) {
            right--;
        }
        //  The Color Matcher
        else {
            // Convert both to lowercase before comparing
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // Mismatch found! Pattern is ruined.
            }
            // If they match, both inspectors take a step inward
            left++;
            right--;
        }
    }
    
    return true; // The inspectors crossed paths without any mismatches!
}

int main() {
    string path = "race car" ;
    
    if (isPalindrome(path)) {
        cout << "Result: It is a valid palindrome!\n";
    } else {
        cout << "Result: Not a palindrome.\n";
    }
    
    return 0;
}