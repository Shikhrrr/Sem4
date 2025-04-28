#include<bits/stdc++.h>
using namespace std;

// Calculate Hamming distance between two strings
int hammingDistance(string str1, string str2) {
    if (str1.length() != str2.length()) {
        cout << "Strings must be of equal length" << endl;
        return -1;
    }
    
    int distance = 0;
    for (size_t i = 0; i < str1.length(); i++) {
        if (str1[i] != str2[i]) {
            distance++;
        }
    }
    return distance;
}

// Calculate required number of redundant bits
int calcRedundantBits(int m) {
    int r = 0;
    while (pow(2, r) < m + r + 1) {
        r++;
    }
    return r;
}

// Generate Hamming code
string generateHammingCode(string data) {
    int m = data.length();
    int r = calcRedundantBits(m);
    int n = m + r;
    
    // Initialize hamming code with placeholder
    string hammingCode(n, '0');
    
    // Determine positions of parity bits (powers of 2)
    vector<int> parityPositions;
    for (int i = 0; i < r; i++) {
        parityPositions.push_back(pow(2, i) - 1);
    }
    
    // Place data bits in non-parity positions
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (find(parityPositions.begin(), parityPositions.end(), i) == parityPositions.end()) {
            hammingCode[i] = data[j++];
        }
    }
    
    // Calculate parity bits
    for (int i = 0; i < r; i++) {
        int parity = 0;
        int pos = parityPositions[i];
        
        for (int j = pos; j < n; j++) {
            if ((j + 1) & (pos + 1)) {
                parity ^= (hammingCode[j] - '0');
            }
        }
        
        hammingCode[pos] = parity + '0';
    }
    
    return hammingCode;
}

// Detect and correct error in received hamming code
pair<bool, string> detectAndCorrectError(string receivedCode) {
    int n = receivedCode.length();
    int r = 0;
    while (pow(2, r) < n + 1) {
        r++;
    }
    
    // Calculate syndrome
    int errorPos = 0;
    for (int i = 0; i < r; i++) {
        int parity = 0;
        int pos = pow(2, i) - 1;
        
        for (int j = 0; j < n; j++) {
            if ((j + 1) & (pos + 1)) {
                parity ^= (receivedCode[j] - '0');
            }
        }
        
        if (parity != 0) {
            errorPos += pow(2, i);
        }
    }
    
    string correctedCode = receivedCode;
    if (errorPos != 0) {
        correctedCode[errorPos - 1] = (correctedCode[errorPos - 1] == '0') ? '1' : '0';
        return {true, correctedCode};
    }
    
    return {false, correctedCode};
}

int main() {
    // Example: Find Hamming distance
    string str1 = "1011";
    string str2 = "1001";
    cout << "Hamming distance between " << str1 << " and " << str2 << ": " 
         << hammingDistance(str1, str2) << endl;
    
    // Example: Error correction using Hamming code
    string data = "1011";
    cout << "\nOriginal data: " << data << endl;
    
    string hammingCode = generateHammingCode(data);
    cout << "Generated Hamming code: " << hammingCode << endl;
    
    // Introduce error (flip a bit)
    string receivedCode = hammingCode;
    int errorPos = 2;
    receivedCode[errorPos] = (receivedCode[errorPos] == '0') ? '1' : '0';
    cout << "Received code (with error at position " << errorPos+1 << "): " << receivedCode << endl;
    
    // Detect and correct error
    pair<bool, string> result = detectAndCorrectError(receivedCode);
    bool errorDetected = result.first;
    string correctedCode = result.second;
    
    if (errorDetected) {
        cout << "Error detected and corrected!" << endl;
        cout << "Corrected code: " << correctedCode << endl;
    } else {
        cout << "No errors detected." << endl;
    }
    
    return 0;
}