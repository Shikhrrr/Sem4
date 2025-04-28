#include <bits/stdc++.h>
using namespace std;

    // Function to calculate CRC remainder
string crcRemainder(string message, string generator) {
    // Make a copy of the message
    string result = message;
    
    // Append zeros to the message (equal to generator length - 1)
    for (int i = 0; i < generator.length() - 1; i++) {
        result += '0';
    }
    
    // Perform CRC division
    for (int i = 0; i <= result.length() - generator.length(); i++) {
        // If the current bit is 1, perform XOR with the generator
        if (result[i] == '1') {
            for (int j = 0; j < generator.length(); j++) {
                result[i + j] = (result[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }
    
    // Return the last (generator length - 1) bits as the remainder
    return result.substr(result.length() - (generator.length() - 1));
}

// Function to check if the received message has any errors
bool crcCheck(string message, string generator) {
    // Perform CRC division
    for (int i = 0; i <= message.length() - generator.length(); i++) {
        if (message[i] == '1') {
            for (int j = 0; j < generator.length(); j++) {
                message[i + j] = (message[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }
    
    // Check if the remainder is all zeros
    for (int i = message.length() - (generator.length() - 1); i < message.length(); i++) {
        if (message[i] != '0') {
            return false;
        }
    }
    return true;
}

int main(void) {
    string message, generator;
    
    cout << "Enter the message bits: ";
    cin >> message;
    
    cout << "Enter the generator polynomial: ";
    cin >> generator;
    
    // Calculate CRC
    string crc = crcRemainder(message, generator);
    
    // Codeword = message + crc
    string codeword = message + crc;
    
    cout << "CRC: " << crc << endl;
    cout << "Transmitted codeword: " << codeword << endl;
    
    // Verify the correctness
    if (crcCheck(codeword, generator)) {
        cout << "No error detected in the transmitted codeword!" << endl;
    } else {
        cout << "Error detected in the transmitted codeword!" << endl;
    }
    
    // Simulate error introduction
    cout << "\nEnter position to introduce error (0-" << codeword.length() - 1 << "): ";
    int errorPos;
    cin >> errorPos;
    
    if (errorPos >= 0 && errorPos < codeword.length()) {
        // Flip the bit at the specified position
        codeword[errorPos] = (codeword[errorPos] == '0') ? '1' : '0';
        cout << "Codeword after introducing error: " << codeword << endl;
        
        // Check for error
        if (crcCheck(codeword, generator)) {
            cout << "No error detected in the modified codeword!" << endl;
        } else {
            cout << "Error detected in the modified codeword!" << endl;
        }
    } else {
        cout << "Invalid position!" << endl;
    }
    
    return 0;
}


