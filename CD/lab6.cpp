#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<string> code;

    string s;
    while(getline(cin, s) and s != "END") {
        code.emplace_back(s);
    }

    int f = 2;

    for (string line : code) {
        int n = line.length();
        for (int i = 0; i<n-1; i++) {
            if (line[i] == '/' and line[i+1] == '*' or ) {
                f = 1;
            }
            if (line[i] == '*' and line[i+1] == '/') {
                f = 0;
            }
        }
    }

    if (f == 0) {
        cout << "Terminating statement. Comment found\n";
    } 
    else if (f==2) {
        cout << "Terminating statement. Comment not found\n";
    } else {
        cout << "Non terminating statement\n";
    }
}