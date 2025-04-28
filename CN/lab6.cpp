#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    string data, generator;
    cout << "Enter data: ";
    cin >> data;
    cout << "Enter generator: ";
    cin >> generator;

    int dataLen = data.length();
    int genLen = generator.length();

    // Append zeros to the data
    string appendedData = data + string(genLen - 1, '0');

    // Perform division
    string remainder = appendedData;
    for (int i = 0; i <= dataLen; i++) {
        if (remainder[i] == '1') {
            for (int j = 0; j < genLen; j++) {
                remainder[i + j] = (remainder[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // Extract the CRC
    string crc = remainder.substr(dataLen, genLen - 1);
    cout << "CRC: " << crc << endl;

    // Transmitted data
    string transmittedData = data + crc;
    cout << "Transmitted data: " << transmittedData << endl;

    // Receiver side
    cout << "Enter received data: ";
    string receivedData;
    cin >> receivedData;

    // Perform division on received data
    remainder = receivedData;
    for (int i = 0; i <= receivedData.length() - genLen; i++) {
        if (remainder[i] == '1') {
            for (int j = 0; j < genLen; j++) {
                remainder[i + j] = (remainder[i + j] == generator[j]) ? '0' : '1';
            }
        }
    }

    // Check if remainder is zero
    bool isError = false;
    for (int i = receivedData.length() - genLen + 1; i < receivedData.length(); i++) {
        if (remainder[i] == '1') {
            isError = true;
            break;
        }
    }

    if (isError) {
        cout << "Error detected in received data." << endl;
    } else {
        cout << "No error detected in received data." << endl;
    }
}