#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s, string t) {
    // If they aren't even the same length, they can't be anagrams
    if (s.length() != t.length()) {
        return false;
    }

    // The Tally Chart: 26 slots (for 26 letters), all starting at 0
    vector<int> tally(26, 0); 

    // Check-In and Check-Out simultaneously
    for (int i = 0; i < s.length(); i++) {
        tally[s[i] - 'a']++; // Add 1 for the letter in string s
        tally[t[i] - 'a']--; // Subtract 1 for the letter in string t
    }

    // The Final Audit: Check if every single slot canceled out to 0
    for (int count : tally) {
        if (count != 0) {
            return false; // Mismatch found!
        }
    }
    
    return true; // Perfect match!
}

int main() {
    string str1 = "aab";
    string str2 = "abb";
    
    if (isAnagram(str1, str2)) {
        cout << "Result: They are valid anagrams.\n";
    } else {
        cout << "Result: Not valid anagrams.\n"; // This will trigger for aab and abb
    }
    
    return 0;
}