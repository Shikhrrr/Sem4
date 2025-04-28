#include <bits/stdc++.h>
using namespace std;

void bitStuff(string &s) {
    int n = s.length();
    
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            c++;
        }
        if (c == 5) {
            s.insert(s.begin()+i+1, '0');
            c = 0;
        }
    }
}

int main() {
    string s;
    cin >> s;

    bitStuff(s);

    cout << s << '\n';
}