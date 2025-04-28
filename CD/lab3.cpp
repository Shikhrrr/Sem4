#include <bits/stdc++.h>
using namespace std;

bool vCon(const string& c) {
    stack<char> b;
    for (char x : c) {
        if (x == '(') b.push(x);
        else if (x == ')') {
            if (b.empty()) return false;
            b.pop();
        }
    }
    return b.empty();
}

bool vIf(const string& s) {
    size_t p = s.find("if");
    if (p == string::npos || p != 0) return false;

    size_t o = s.find('(', p + 2);
    size_t c = s.find(')', o);
    if (o == string::npos || c == string::npos) return false;

    string cond = s.substr(o + 1, c - o - 1);
    return vCon(cond);
}

int main() {
    string s;
    cout << "Enter an if statement: ";
    getline(cin, s);

    if (vIf(s)) {
        cout << "Valid if statement\n";
    } else {
        cout << "Invalid if statement\n";
    }

    return 0;
}
