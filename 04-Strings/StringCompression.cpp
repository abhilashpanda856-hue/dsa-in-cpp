#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars) {
    int write = 0; // Where we write on our clipboard
    int read = 0;  // Where we are looking on the conveyor belt

    while (read < chars.size()) {
        char currentChar = chars[read];
        int count = 0;

        //  The Counter: Keep reading forward as long as the items match
        while (read < chars.size() && chars[read] == currentChar) {
            read++;
            count++;
        }

        // Write the item name (e.g., 'a')
        chars[write] = currentChar;
        write++;

        //  Write the count, but ONLY if it's greater than 1
        if (count > 1) {
            // Convert the integer (like 12) into a string ("12")
            string countStr = to_string(count); 
            
            // Write each digit into its own separate slot ('1', then '2')
            for (char digit : countStr) {
                chars[write] = digit;
                write++;
            }
        }
    }
    
    // The write pointer naturally represents the new length of the compressed array
    return write; 
}

int main() {
    vector<char> items = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    
    int newLength = compress(items);
    
    cout << "Compressed array: ";
    for (int i = 0; i < newLength; i++) {
        cout << items[i] << " ";
    }
    cout << "\nNew Length: " << newLength << "\n";
    
    return 0;
}