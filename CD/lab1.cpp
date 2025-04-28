#include <bits/stdc++.h>
using namespace std;

int main () {
    stack<char> s;
    string a;
    cin >> a;

    int k = 0;

    while (k < a.size() and a[k] == ' ') {
        k++;
    }

    if (a[k] == '+' or a[k] == '*' or a[k] == '/') {
        cout << "INVALID" << endl;
        return 0;
    }

    for (int i = k; i < a.size(); i++) {
        if (a[k] == ' ') continue;
        if (!((a[i] >= '0' and a[i] <= '9') or (a[i] == '+' or a[i] == '-' or a[i] == '/' or a[i] == '*'))) {
            cout << "INVALID" << endl;
            return 0;
        }

        bool x = 0, y = 0;
        if (!s.empty()) {
            x = (s.top() == '+' or s.top() == '-' or s.top() == '/' or s.top() == '*');
            y = (a[i] == '+' or a[i] == '-' or a[i] == '/' or a[i] == '*');
        }
        if (x and y) {
            cout << "INVALID" << endl;
            return 0;
        }
        s.push(a[i]);
    } 
    bool x = (s.top() == '+' or s.top() == '-' or s.top() == '/' or s.top() == '*');
    if (x) {
        cout << "INVALID" << endl;
    } else {
        cout << "VALID" << endl;
    }
}